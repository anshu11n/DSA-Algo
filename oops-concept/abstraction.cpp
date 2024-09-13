// Abstraction- Hiding imoportant info and show important parts
// Access modifiers

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Abstract class provides a blue print from which other class can be driven
// object can't be created from them

class Shape{
    virtual void draw() = 0; // pure virtual function
    // if pure virtual function then automatic abstract class
    // obj cant be made
};

class Circle : public Shape{
public:
    void draw(){
        cout<<"drawing a circle"<<endl;
    }
};

// Static keyword
// variables declared as static in a function are created and initialised once for the lifetime of the program. 

// static variables in a class are created and initialised once. Tjhey are shared by all the objects of the class

void func(){
    static int x=0; // now this will me made separately and made only once -> this statement will run only one time
    cout<<x<<endl;
    x++;
}

class A{
    public:
    int x; 

    // if this x will me made static then for all objects only one x will be created and all function eill work on that x only- single x

    void incX(){
        x=x+1;
    }
};


// objects made with static keyword will persist in memory till last
class ABC{
    public:
    ABC(){
        cout<<"const"<<endl;
    }

    ~ABC(){
        cout<<"dest"<<endl;
    }
};


void solve(){
    func();
    func();
    func();
    // x=0,1,2

    A obj1, obj2;
    obj1.x=100;
    obj2.x=200;

    obj1.incX();
    obj2.incX();

    // obj.incX();
    cout<<obj1.x<<endl;

    if(true){
        static ABC obj;
    }

    cout<<"end of program"<<endl;

    // without static
    // const
    // dest
    // end of prog

    // with static
    // const
    // end of program
    // dest
    // will remain till last
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