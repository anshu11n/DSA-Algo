#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin>>n;
    int cnt=0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            cout<<i<<" "<<n/i<<endl;
            if(i == n/i) cnt++;
            else cnt+=2;
        }
    }

    // O(sqrt(n))

    // x = p1^n1 * p2^n2 .......
    // total divisors = (n1+1)*(n2+1)*(n3+1)

    cout<<"count: "<<cnt<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}