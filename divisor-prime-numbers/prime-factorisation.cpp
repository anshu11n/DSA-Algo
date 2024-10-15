#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    // O(sqrt(n))
    int n; cin>>n;
    bool isPrime = true;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            isPrime = false;
            break;
        }
    }

    cout<<isPrime<<endl;

    // Prime factorization

    vector<int> prime_factor;
    int i;
    for(i=2; i*i<=n; i++){
        while(n%i==0){
            prime_factor.push_back(i);
            n/=i;
        }
    }

    if(n>1){
        prime_factor.push_back(n);
        // i>1 it means one prime number is left at last, coz prime dont have a divisor lesser than sqrt(n)
    }

    // atleast one prime exsist before sqrt(n) for composite
    // when we update n, after finishing all occurences of a prime number say 2, we got new n, now loop will run till updated sqrt(n)

    for(int i=0; i<prime_factor.size(); i++){
        cout<<prime_factor[i]<<" ";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}