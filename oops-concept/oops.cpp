#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Teacher {
public:
    // Constructor Overloading - Polymorphism

    // It is not parameterised constuctor
    Teacher(){
        // no return type
        // always public
        // memory allocation happens when constuctor called


        cout<<"Constuctor Called"<<endl;
        dept = "CSE";
    }

    // parameterised

    Teacher(string name, string dept, string subject, double salary){
        cout<<"Constuctor Called"<<endl;

        // this-> prop = (*this).prop;

        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    Teacher(Teacher &obj){
        // original obj passed

        cout<<"Custom copy construcor"<<endl;
        this->name = obj.name;
        this->dept = obj.dept;
        this->salary = obj.salary;
    }


    // property / attribute
    string name;
    string dept;
    string subject;
    double salary;

    // methods
    void changeDept(string newDept){
        dept = newDept;
    }

    //setter 
    void setSalary(double s){
        salary = s;
    }

    // getter
    double getSalary(){
        return salary;
    }

    void getInfo(){
        cout<<"name: "<<name<<endl;
        cout<<"subject: "<<subject<<endl;
    }
};

class Student{
    public:
    string name; // statically allocated memory
    double* cgpaPtr; // dynamically allocated  memory assigned in heap

    Student(string name, double cgpa){
        this->name=name;
        cgpaPtr = new double; // new pointer for cgpaPtr
        *cgpaPtr = cgpa;
    }

    // this keywork neede when both names are same
    Student(Student &obj){
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    // destructor
    ~Student(){
        // for dynamic memory manual destructor should be made
        cout<<"Desctructor called"<<endl;
        delete cgpaPtr; // manual deletion for dynamic memory

        // issues  can occur like memory leak, memory may get occupied without ptr 
    }

    void getInfo(){
        cout<<name<<endl;
        cout<<*cgpaPtr<<endl;
    }
};

void solve(){
    Teacher t1; // automatic constructor call

    // space in memory get occupied once object is created
    // class dont take space

    // cout <<  t1.dept << endl;

    Teacher t2("abc", "EEE", "C++", 25000);
    t2.getInfo();

    Teacher t3(t2); // Copy Constuctor invoked
    t3.getInfo();


    // shallow copy - copies all member values from one object to another

    // variable are created in stack memory, function calls
    // new int[5] - allocated at run time

    int x=5, y=0; // memory allocated in stack at compile time but

    // new int, new int[5] - memory allocated in heap dynamically allocated

    Student s1("rahul", 8.9);
    s1.getInfo();

    Student s2(s1);
    s2.name = "neha";
    *(s2.cgpaPtr) = 9.2;

    s1.getInfo();
    s2.getInfo();

    // s1's cgpa also get changed 
    // this is the problem of shallow copy
    // shallow copy copies the value
    // hence it copies the address of cgpa, and when we changed the value at that address, value for both addr will change

    // DEEP Copy - Manually contructor need to be made

    // Destructor- delete

    // ptr -> pointer : delete ptr deletes the memory in the heap that our pointer points to, ptr will still remain not get deleted
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}