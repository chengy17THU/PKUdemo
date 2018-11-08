#include<iostream>
#include<fstream>
#include<cstring>
/// an example class template

using namespace std;

// 1: template derived from template
template<typename T1, typename T2>
class A
{
public:
    T1 v1;
    T2 v2;
};

template<typename T1, typename T2>
class B: public A<T2, T1>
{
public:
    T1 v3;
    T2 v4;
};

template<typename T>
class C: public B<T, T>
{
    T v5;
};

// 2: template derived from template instances
template<class T1, class T2>
class AA
{
    T1 v1;
    T2 v2;
};

template<class T>
class BB: public AA<int, double>
{
    T v3;
};

// 3: template derived from normal class
class AAA
{
    int v1;
};

template<class T>
class BBB: public AAA
{
    T v2;
};

// 4: normal class derived from template instances
class CCC: public BBB<int>
{
    int v1;
};
int main()
{
    B<int, double> obj1;
    C<int> obj2;
    BB<char> obj3;
    BBB<int> obj4;
    CCC obj5;
    return 0;
}
