#include <iostream>
#include <algorithm>

using namespace std;

class A
{
    int i;
    public:
    A(int n):i(n) {}// ctor
    bool operator < (const A &a) const{
    cout << i << "<" << a.i << "?" << endl;
    return false;} // rule for comparison can be customized

    bool operator == (const A &a) const{
    cout << i << "==" << a.i << "?" << endl;
    return i==a.i;}
};

int main()
{
    A a[5]={A(0), A(1), A(2), A(3), A(4)};
    cout << binary_search(a, a+5, A(9)) << endl;
    return 0;
}
