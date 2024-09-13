#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
// can be solved using merge sort, fenwick tree, segment tree

class SGTree{
    public:
    vector<ll> seg;

    SGTree(int n){
        seg.resize(4*n, 0);
    }

    void build(int ind, int low, int high, vector<int> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)>>1;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    void update(int ind, int low, int high, int i, int val){
        if(low==high){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)>>1;

        if(i<=mid){
            update(2*ind+1, low, mid, i, val);
        }else{
            update(2*ind+2, mid+1, high, i, val);
        }

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    ll query(int ind, int low, int high, int l, int r){
        if(high<l || r<low) return 0;
        if(l<=low && high<=r) return seg[ind];

        int mid = (low+high)>>1;
        ll lf = query(2*ind+1, low, mid, l, r);
        ll rt = query(2*ind+2, mid+1, high, l, r);

        return lf + rt;
    }
};


void solve(){
    int n; cin>>n;
    vector<int> arr(n);
    vector<pair<int,int>> pr;
    
    SGTree sg(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
        pr.push_back({arr[i], i});
    }

    ll ans=0;

    sort(pr.begin(), pr.end());

    for(int i=0;i<n;i++){
        int num = pr[i].first, idx = pr[i].second;
        // cout<<num<<" "<<idx<<endl;

        ans += sg.query(0, 0, n-1, idx+1, n-1);
        sg.update(0, 0, n-1, idx, 1);

        // for(int i=0;i<4*n;i++){
        //     cout<<sg.seg[i]<<" ";
        // } cout<<endl;
    }

    cout<<ans<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}