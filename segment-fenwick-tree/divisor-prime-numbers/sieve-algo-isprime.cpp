#include<bits/stdc++.h>
using namespace std;
#define ll long long

//  qus- q queries 1e7, given n 1e7, tell whether n is prime or not, so we are gonna use sieve algo here

const int N = 1e7+10; 
vector<bool> isPrime(N, 1);
// assume all true

void solve(){
    // T.C. = O(N*log(log n)) 

    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<N; i++){
        if(isPrime[i] == true){
            for(int j=2*i; j<N; j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i=1; i<=100; i++){
        cout<<isPrime[i]<<" ";
    } cout<<endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}