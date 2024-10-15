#include<bits/stdc++.h>
using namespace std;
#define ll long long

class SGTree{
    vector<int> seg;

    public:
    SGTree(int n){
        seg.resize(4*n);
    }

    void build(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)>>1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r){


        // (l r) (low high) || (low high) (l r) no overlap
        if(high<l || r<low) return INT_MAX;

        // complete overlap
        if(l<=low && high<=r) return seg[ind];

        // partial overlap
        int mid = (low+high)>>1;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);

        return min(left, right);
    }

    void update(int ind, int low, int high, int i, int val, vector<int> &arr){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)>>1;
        if(i<=mid){
            update(2*ind+1, low, mid, i, val, arr);
        }else{
            update(2*ind+2, mid+1, high, i, val, arr);
        }

        seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);
    }
};

void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    SGTree sg(n);
    sg.build(0, 0, n-1, arr);

    int q; cin>>q;
    while(q--){
        int type; cin>>type;
        if(type==1){
            int l, r; cin>>l>>r;
            cout<<sg.query(0, 0, n-1, l, r)<<endl;
        }else{
            int i, val; cin>>i>>val;
            arr[i] = val;
            sg.update(0, 0, n-1, i, val, arr);
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