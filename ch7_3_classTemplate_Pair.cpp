#include<iostream>
#include<fstream>
#include<cstring>
/// an example class template

using namespace std;

// template<class T1, class T2>
template<typename T1, typename T2>
class Pair
{
public:
    T1 key;
    T2 val;
    Pair(T1 k, T2 v): key(k), val(v){}
    bool operator < (const Pair<T1, T2> &p) const;
    template<typename T>
    void func(T tt) {cout << tt;}
};

// template<class T1, class T2>
template<typename T1, typename T2>
bool Pair<T1, T2>::operator < (const Pair<T1, T2> &p) const
{
    return key < p.key;
}

int main()
{
    Pair<string, int> student("Tom", 19);
    cout << student.key << " " << student.val;
    student.func(12);
    return 0;
}
