//
// Created by cheng on 12/13/18.
//

#include <set>
#include <iostream>

using namespace std;

template <class T>
void prt(T first, T last)
{
    for(; first!=last; first++)
        cout << *first << " ";
    cout << endl;
}

class  A
{
private:
    int n;
public:
    A(int n_): n(n_) {}
    friend bool operator< (const A & a1, const A & a2) {return a1.n < a2.n;}
    friend ostream &operator << (ostream & o, const A &a2) {return o << a2.n;}
    friend class MyLess;
};

class MyLess
{
public:
    // class MyLess is a function obj
    bool operator()(const A &a1, const A &a2)
    // compare according to number on single digit
    { return (a1.n%10)<(a2.n%10); }
};

typedef multiset<A> MS1;
typedef multiset<A, MyLess> MS2;

int main()
{
    // multiset
    const size_t SZ=6;
    A a[SZ] = {4, 22, 19, 8, 33, 40};
    MS1 ms1;
    ms1.insert(a, a+SZ);
    ms1.insert(22);
    cout << ms1.count(22) << endl;
    prt(ms1.begin(), ms1.end());
    cout << *ms1.find(19) << "," << *ms1.lower_bound(22) << "," << *ms1.upper_bound(22) << endl;
    MS1::iterator pp = ms1.erase(ms1.lower_bound(22), ms1.upper_bound(22));
    prt(ms1.begin(), ms1.end());
    cout << *pp << endl;
    MS2 ms2;
    ms2.insert(a, a+SZ);
    prt(ms2.begin(), ms2.end());

    // set
    typedef set<int>::iterator IT;
    int b[5] = {3, 4, 6, 1, 2};
    set<int> st(b, b+5);
    pair<IT, bool> result;
    result = st.insert(5); // insert的返回值本来就是个pair？所以result的second是Bool，这样也说得通
    if(result.second)
        cout << *result.first << " element inserted" << endl;
    if(st.insert(5).second)
        cout << *result.first << " element inserted" << endl;
    else
        cout << *result.first << " element exists" << endl;
    pair<IT, IT> bounds = st.equal_range(4);
    cout << *bounds.first << "," << *bounds.second;
    return 0;
}