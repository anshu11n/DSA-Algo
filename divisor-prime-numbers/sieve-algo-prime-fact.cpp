#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e7+10;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0), hp(N, 0); // highest prime, lowest prime

void solve(){
    // lowest / highest prime of a number

    isPrime[0] = isPrime[1] = false;
    
    for(int i=2; i<N; i++){
        if(isPrime[i] == true){
            for(int j=2*i; j<N; j+=i){
                isPrime[j] = false;
                hp[j] = i;

                if(lp[j]==0){
                    lp[j]=i;
                }
            }
        }
    }

    int num; cin>>num;
    vector<int> primefac;

    while(num>1){
        int prime = hp[num];
        while(num % prime == 0){
            num/=prime;
            primefac.push_back(prime);
        }
    }
    
    // O(logn)

    for(int i=0 ; i<primefac.size(); i++){
        cout<<primefac[i]<<" ";
    } cout<<endl;
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