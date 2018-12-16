//
// Created by cheng on 12/5/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

// part 2
int sumSquares(int tot, int val)
{
    return tot+val*val;
}

template <typename T>
void printRange(T first, T last)
{
    for(; first != last; ++first)
        cout << *first << " ";
    cout << endl;
}

template <class T>
class sumPowers
{
private:
    int power;
public:
    sumPowers(int p):power(p) {}
    const T operator() (const T &tot, const T &val)
    {
        // objects of such classes with operator '()' overloaded are called function object
        // calculate 'power' powers of 'val', then add to 'tot'
        T v = val;
        for(int i=0; i < power-1; ++i)
            v = v*val;
        return tot+v;
    }
};

// part 2
class MyLess
{
public:
    bool operator() (int a1, int a2)
    {
        if ((a1%10)<(a2%10))
            return true;
        else
            return false;
    }
};

bool MyComp(int a1, int a2)
{
    if ((a1%10)<(a2%10))
        return false;
    else
        return true;
}

template <class T, class pred>
T MyMax(T first, T last, pred myless)
{
    T tmpMax = first;
    while(first != last) {
        if (myless(*tmpMax, *first))
            tmpMax = first;
        ++ first;
    }
    return tmpMax;
}

int main()
{
    // part 1
    const size_t SIZE =10;
    int a1[]={1,2,3,4,5,6,7,8,9,10};
    vector<int> v(a1, a1+SIZE);
    printRange(v.begin(), v.end());
    int result = accumulate(v.begin(), v.end(), 0, sumSquares);
    cout << result << endl;
    result = accumulate(v.begin(), v.end(), 0, sumPowers<int>(3));
    cout << result << endl;
    result = accumulate(v.begin(), v.end(), 0, sumPowers<int>(4));
    cout << result << endl;
    result = accumulate(v.begin(), v.end(), 0, sumPowers<int>(1));
    cout << result << endl;
    // cout << "Fuck you, leather man!"<< endl;
    // part 2
    int a[]={35, 7, 13, 19, 12};
    cout << * MyMax(a, a+5, MyLess()) << endl;
    cout << * MyMax(a, a+5, MyComp) << endl;
    return 0;
}
