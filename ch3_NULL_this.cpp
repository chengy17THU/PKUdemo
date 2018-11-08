#include <iostream>
 using namespace std;

 class A
 {
     int i;
 public:
    void Hello(){cout << "Hello" << endl;}
 };

 int main()
 {
     A* p = nullptr; // a null pointer
     p->Hello(); // it DO print "hello"
     return 0;
 }
