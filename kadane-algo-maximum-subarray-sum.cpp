#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    int ansst=-1, ansen=-1;

    int maxi=INT_MIN, sum=0;
    int start=-1;

    for(int i=0; i<n; i++){
        if(sum==0) start = i;

        sum+=a[i];
        if(sum > maxi){
            maxi=sum;
            ansst = start; ansen = i;
        }

        if(sum<0) sum=0;
    }

    cout<<ansst<<" "<<ansen<<endl;
    cout<<maxi<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}