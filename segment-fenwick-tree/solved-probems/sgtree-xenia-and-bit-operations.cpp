#include<bits/stdc++.h>
using namespace std;
#define ll long long

class SGTree{
    public:
    vector<int> seg;
    SGTree(int n){
        seg.resize(4*n);
    }

    void build(int ind, int low, int high, vector<int> &v, int fl){
        if(low==high){
            seg[ind] = v[low];
            return;
        }

        int mid = (low+high)>>1;

        build(2*ind+1, low, mid, v, !fl);
        build(2*ind+2, mid+1, high, v, !fl);

        if(fl==0) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }

    void update(int ind, int low, int high, int i, int val, int fl){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)>>1;

        if(i<=mid){
            update(2*ind+1, low, mid, i, val, !fl);
        }else{
            update(2*ind+2, mid+1, high, i, val, !fl);
        }

        if(fl==0) seg[ind] = seg[2*ind+1] | seg[2*ind+2];
        else seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
    }
};

void solve(){
    int n, m; cin>>n>>m;

    int sz=(1<<n);
    vector<int> v(sz);
    for(int i=0;i<sz;i++) cin>>v[i];

    int fl;
    if(n & 1) fl=0;
    else fl=1;

    SGTree sg(sz);
    sg.build(0, 0, sz-1, v, fl);

    while(m--){
        int l, r; cin>>l>>r;
        l--;
        sg.update(0, 0, sz-1, l, r, fl);
        v[l] = r;
        cout<<sg.seg[0]<<endl; 
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