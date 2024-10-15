#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct segNode{
    int val, open, close, full;
    segNode(){
        this->open = 0;
        this->close = 0;
        this->full = 0;
    }
};

segNode merge(segNode node1, segNode node2){
    segNode ans = segNode();
    int mini = min(node1.open, node2.close);

    ans.full = node1.full + node2.full + mini;

    ans.open = node1.open + node2.open - mini;

    ans.close = node1.close + node2.close - mini;

    return ans;
}

class SGTree{
    public:
    vector<segNode> seg;

    SGTree(int n){
        seg.resize(4*n);
    } 

    void build(int ind, int low, int high, string &s){
        if(low==high){
            seg[ind].open = s[low]=='(';
            seg[ind].close = s[low]==')';
            seg[ind].full=0;
            return;
        }

        int mid = (low+high)>>1;

        build(2*ind+1, low, mid, s);
        build(2*ind+2, low, mid, s);

        seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
    }

    segNode query(int ind, int low, int high, int l, int r){
        
        if(r<low || high<l) return segNode();

        if(l<=low && high<=r) return seg[ind];

        int mid = (low+high)>>1;

        segNode lf = query(2*ind+1, low, mid, l, r);
        segNode rt = query(2*ind+1, mid+1, high, l, r);

        return merge(lf, rt);
    }
};

void solve(){
    string s; cin>>s;
    int n=s.length();
    int m; cin>>m;

    SGTree sg(n);
    sg.build(0, 0, n-1, s);

    for(int i=0;i<sg.seg.size();i++){
        cout<<sg.seg[i].open<<" "<<sg.seg[i].close<<" "<<sg.seg[i].full<<endl;
    }

    while(m--){
        int l, r; cin>>l>>r;
        l--; r--;

        cout<<sg.query(0, 0, n-1, l, r).full*2<<endl;
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