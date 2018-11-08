#include<iostream>
using namespace std;

class CDemo
{
    int n;
public:
    CDemo(int i=0):n(i){}
    CDemo operator++(); // ++ at front
    CDemo operator++(int); // ++ at back
    operator int(){return n;}; // 强制类型转换运算符的重载
    friend CDemo operator--(CDemo &);
    friend CDemo operator--(CDemo &, int);
};

CDemo CDemo::operator++()
{
    n++;
    return *this;
}

CDemo CDemo::operator++(int i)
{
    CDemo tmp(*this);
    n++;
    return tmp; //return a temp CDemo obj
}

CDemo operator--(CDemo & cd)
{
    cd.n--;
    return cd;
}

CDemo operator--(CDemo & cd)
{
    CDemo tmp(cd);
    cd.n--;
    return tmp;
}

int main()
{
    CDemo d(5);
    cout << (d++) << ",";
    cout << d << ",";
    cout << (++d) << ",";
    cout << d << endl;
    cout << (d++) << ",";
    cout << d << ",";
    cout << (++d) << ",";
    cout << d << endl;
    return 0;
}
