#include<bits/stdc++.h>
using namespace std;
#define ll long long

// O(n+m)
// p - pattern, s-string

// string = a a b a a c a a b a a d
// lps =    0 1 0 1 2 0 1 2 3 4 5 0
// longest prefix that matches suffix 

// string = a a b # a a b a a b a a b
// lps =    0 1 0 0 1 2 3 1 2 3 1 2 3
// longest prefix that matches suffix 

vector<int> kmp(string s){
    int n=s.size();
    vector<int> lps(n, 0);

    for(int i=1; i<n; i++){
        int prev_idx = lps[i-1];

        while(prev_idx > 0 && s[i] != s[prev_idx]){
            prev_idx = lps[prev_idx-1];
        }

        lps[i] = prev_idx + (s[i] == s[prev_idx]);
    }

    // At each i, we will ask i-1 what is lps, lps[i-1], previous index lps ,matching is stored in prev_idx

    // so we will simply do it till we get s[i] == s[prev_idx] or prev_idx==0, which means we got the matching

    return lps;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    

    return 0;
}