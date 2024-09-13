#include<bits/stdc++.h>
using namespace std;
#define ll long long

// bit always from index 1
int n;
vector<int> bit;

// log n
// adding val to all the place of 2's power
void update(int id, int val){
    while(id<=n){
        bit[id] += val;
        id += (id & -id); // will set the next bit - reverse operation of query
    }
}

// query (7) = range(1,4) + range(5,6) + range(7,7)

// query gives answer for [ 1 to id ]
// log n
int query(int id){
    int ans=0;

    while(id>0){
        ans+=bit[id];
        id -= (id & -id); // will remove the last set bit
    }

    return ans;
}
 
void solve(){
    cin>>n;
    bit.resize(n+1, 0);
    
    vector<int> a(n+1);

    // n log n
    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i, a[i]); // build fenwick tree
    }

    int q; cin>>q;
    // q log n
    while(q--){
        int type; cin>>type;
        if(type==1){
            // find sum in range l to r
            int l,r; cin>>l>>r;
            int ans = query(r) - query(l-1);
            cout<<ans<<endl;
        }else{
            // replace
            int id, val; cin>>id>>val;
            update(id, -a[id]); // remove effect of previous
            a[id] = val;
            update(id, val);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}