#include<iostream>

using namespace std;

class Base
{
public:
    // Base() {cout << "Base ctor" << endl;}
    virtual ~Base(){cout << "Base dtor" << endl;};
};

class Derived:public Base
{
public:
    // Derived() {cout << "Base ctor" << endl;}
    ~Derived(){cout << "Derived dtor" << endl;};
};
int main()
{
    // Derived d;
    Base * pBase;
    pBase = new Derived;
    delete pBase;
    return 0;
}
