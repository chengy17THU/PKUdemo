#include<iostream>

using namespace std;

class Base
{
public: // fun1 is virtual while fun2 is not
    void fun1() {fun2();}
    virtual void fun2() {cout << "Base::fun2() called" << endl;}
};

class Derived:public Base
{
public:
    virtual void fun2() {cout << "Derived::fun2() called" << endl;}
};
int main()
{
    Derived d;
    Base * pBase = &d;
    pBase->fun1();
    return 0;
}
