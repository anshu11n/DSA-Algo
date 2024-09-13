// compile time poly- eg. constructor overloading, function overloading
// run time poly

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// COMPILE TIME: function overloading - name same, different parameters

// RUN TIME POLYM- Dynamic 
// Funtion overriding- inheritance
// parent and child both contain same function with different implementation
// parent class function is overriden
// at run time it is decided which function will be used

// Virtual Funtions: RUN TIME POLY
// expects that child class will reimplement it 

class Parent{
public:
    void show(int x){
        cout<<"int"<<endl;
    }

    void show(char ch){
        cout<<"char"<<endl;
    }

    void getInfo(){
        cout<<"Parent Class"<<endl;
    }

    virtual void hello(){
        cout<<"hello from parent"<<endl;
    }
};

class Child : public Parent{
    public:
    void getInfo(){
        cout<<"Child Class"<<endl;
    }

    void hello(){
        cout<<"hello from child"<<endl;
    }
};

void solve(){
    Parent p1;
    p1.getInfo();


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

