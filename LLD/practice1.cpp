#include<bits/stdc++.h>
using namespace std;


class B {

    public :
    B(){
        cout << "Constructor of B is clled" << endl;
    }

    // class whose object will be created
    void f1(){
        cout << "F1 called by B" << endl;
    }
    virtual ~B(){
        cout << "Destrucor of B is called " << endl;
    }
};

class A : public B{

    public :
    A(){
        cout << "Constructor of A is called " << endl;
    }

    void f1(){
        cout << "F1 called by A" << endl;
    }

    ~A(){
        cout << "Destructor of A is called" << endl;
    }
};

int main(){

    B* ptr = new A();

    ptr-> f1(); // calls f1 
    // A is not a abstract class : no pure virtual functions
    // only if i write the virtual keyword
    // the compile time dso[atch is bound to the base class function based on pointer type

    // object of A 
    // A() -> calls the object for base class
    // B() -> A() 
    delete ptr;
    return 0;
}