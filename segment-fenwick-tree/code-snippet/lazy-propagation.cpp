#include<bits/stdc++.h>
using namespace std;
#define ll long long

/*

FOR RANGE UPDATES

lazy node will be there:-

update prev remaining updates

if complete overlap:
- update the node
- lazy propagate to down and return

if partially overlaps:
- left + right

if no overlaps: return

*/

class ST{
    vector<int> seg, lazy;
public:
    ST(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high)>>1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void update(int ind, int low, int high, int l, int r, int val){   
        // update any previous update, if any, and propagate downwards
        if(lazy[ind] != 0){
            seg[ind] += lazy[ind]*(high-low+1);

            // propagate down for remaining childrens

            // check for children
            if(low != high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        // no overlap, simply return
        // l r low high || low high l r
        if(r < low || high < l){
            return;
        }

        // complete overlap
        // l low high r
        // update the node and updaate lazy for further updation
        if(l<=low && high<=r){
            seg[ind] += val*(high-low+1);

            if(low!=high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }

            return;
        }

        int mid = (low + high) >> 1;
        update(2*ind+1, low, mid, l, r, val);
        update(2*ind+2, mid+1, high, l, r, val);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    int query(int ind, int low, int high, int l, int r){
        // update, if any updates are remainig
        // same as update logic
        if(lazy[ind]!=0){
            seg[ind] += lazy[ind]*(high-low+1);

            if(low!=high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }

            lazy[ind] = 0;
        }

        if(r < low || high < l) return 0;
        if(l<=low && high<=r) return seg[ind];

        int mid = (low+high)>>1;
        int lf = query(2*ind+1, low, mid, l, r);
        int rt = query(2*ind+1, mid+1, high, l, r);

        return lf+rt;
    }
};

void solve(){
    int n; cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }

    ST sg(n);
    sg.build(0, 0,  n-1, arr);

    int q; cin>>q;
    while(q--){
        int type; cin>>type;

        if(type==1){
            int l, r; cin>>l>>r;
            cout<<sg.query(0, 0, n-1, l, r)<<endl;
        }else{
            int l, r, val;
            cin>>l>>r>>val;
            sg.update(0, 0, n-1, l, r, val);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}