#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class A
{
    int i;
public:
    A(int n):i(n) {}
    friend bool operator < (const A &a1, const A &a2);
    friend bool operator == (const A &a1, const A &a2);
    friend ostream & operator << (ostream & o, const A &a);
};

bool operator < (const A &a1, const A &a2)
{
    return a1.i < a2.i;
}

bool operator == (const A &a1, const A &a2)
{
    return a1.i == a2.i;
}

ostream & operator << (ostream & o, const A &a)
{
    return o << a.i;
}

template <typename T>
void printList(const list<T> & lst)
{
    int tmp = lst.size();
    if(tmp > 0)
    {
        typename list<T>::const_iterator i; // interesting
        i = lst.begin();
        for (i = lst.begin(); i!=lst.end();i++)
            cout << *i << ",";
    }
    cout << endl;
}

int main()
{
    list<A> lst1, lst2;
    lst1.push_back(1);lst1.push_back(3);lst1.push_back(2);lst1.push_back(4);lst1.push_back(2);
    lst2.push_back(10);lst2.push_front(20);lst2.push_back(30);lst2.push_back(30);lst2.push_back(30);
    lst2.push_front(40);lst2.push_back(40);
    cout << "lst1: "; printList(lst1);
    cout << "lst2: "; printList(lst2);
    lst2.sort();
    cout << "lst2, sorted: "; printList(lst2);

    lst2.pop_front();
    cout << "lst2, front-popped: "; printList(lst2);
    lst1.remove(2); // remove every element equal to A(2)
    cout << "lst1, elements eq. to A(2) removed: "; printList(lst1);
    lst2.unique();
    cout << "lst2, after removing all element eq. to the 1 ahead: "; printList(lst2);
    lst1.merge(lst2);
    cout << "lst1, merging lst2: ";printList(lst1);
    cout << "lst2, merged into lst1: ";printList(lst2);
    lst1.reverse();
    cout << "lst1, reversed:";printList(lst1);

    lst2.push_back(100);lst2.push_back(200);lst2.push_back(300);lst2.push_back(400);
    cout << endl;
    printList(lst1);printList(lst2);
    list<A>::iterator p1, p2, p3;
    p1 = find(lst1.begin(), lst1.end(), 3);
    p2 = find(lst2.begin(), lst2.end(), 200);
    p3 = find(lst2.begin(), lst2.end(), 400);
    lst1.splice(p1, lst2, p2, p3); // [p2, p3) is removed from lst2,and inserted into lst1 at p1
    printList(lst1);printList(lst2);
    return 0;
}
