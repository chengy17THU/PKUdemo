#include<iostream>
#include<cstring>

using namespace std;

class CArray
{
    int sz;
    int * ptr;
public:
    CArray(int s=0);
    CArray(const CArray & ca);
    ~CArray()
    {
        if (!ptr)
            delete [] ptr;
    }
    int & operator[](int i) {return ptr[i];}
    inline CArray & operator=(const CArray & ca);
    inline void push_back(int i);
    int length()
    {
        return sz;
    }
};

CArray::CArray(int s):sz(s)
{
    if (!s)
        ptr = nullptr;
    else
        ptr = new int[s];
}
CArray::CArray(const CArray& ca)
{
    if (ca.sz==0)
    {
        ptr = nullptr;
        sz = 0;
    }
    else
    {
        sz = ca.sz;
        ptr = new int[ca.sz];
        memcpy(ptr,ca.ptr,sizeof(int)*ca.sz);
    }
}
void CArray::push_back(int i)
{
    if (!ptr)
        ptr = new int[1]; // if ptr is nullptr
    else
    {
        int * tmpptr = new int[sz+1]; // declare a new pointer
        memcpy(tmpptr,ptr,sizeof(int)*sz);
        delete [] ptr;
        ptr = tmpptr;
    }
    ptr[sz++] = i;
}

CArray & CArray::operator=(const CArray & ca)
{
    if (ptr==ca.ptr)
        return *this;
    if (!ca.ptr)
    {
        if (ptr) delete [] ptr;
        ptr = nullptr;
        sz = 0;
        return *this;
    }
    if (sz < ca.sz)
    {
        if (ptr)
            delete [] ptr;  // can not delete a nullptr
        ptr = new int[ca.sz];
    }
    memcpy(ptr,ca.ptr,sizeof(int)*ca.sz);
    sz = ca.sz;
    return *this;
}
int main()
{
    CArray a; // nullptr
    for (int i=0;i<5;++i)
        a.push_back(i);
    CArray a2, a3;
    a2 = a;
    for (int i=0;i<a.length();++i)
        cout << a2[i]<<" ";
    a2 = a3;
    for (int i=0;i<a2.length();++i)
        cout <<a2[i]<<" ";
    cout << endl;
    a[3]=100;
    CArray a4(a);
    for (int i=0;i<a4.length();++i)
        cout << a4[i]<<" ";
    return 0;
}
