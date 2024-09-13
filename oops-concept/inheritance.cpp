#include<bits/stdc++.h>
using namespace std;
#define ll long long

// inheritance
class Person{
    public:
    string name;
    int age;

    Person(){
        cout<<"Parent const."<<endl;
    }

    Person(string name, int age){
        cout<<"Parent const."<<endl;

        this->name = name;
        this->age = age;
    }

    ~Person(){
        cout<<"Parent dest."<<endl;
    }
};

class Stud: public Person{
    // name age
    public:
    int roll;

    Stud(string name, int age, int roll) : Person(name, age){

        // this is how you write constructor code for inhertance
        cout<<"Child const."<<endl;
        this->roll = roll;
    }

    ~Stud(){
        cout<<"child dest."<<endl;
    }

    void getInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
    }
};

//  multiple inhertiance

// a child have multiple parents

// TA's are both teacher and Student

class Student{
    public:
    string name;
    int roll;
};

class Teacher{
    public:
    string subject;
    double salary;
};

class TA : public Student, public Teacher{
    public:
    string researchArea;
};

void solve(){
    // Stud ss;
    // ss.name = "vivek";
    // ss.age = 21;
    // ss.getInfo();

    Stud s1("raj", 21, 1234);
    s1.getInfo();

    // parent const. then child const.
    // opposite for destructor
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