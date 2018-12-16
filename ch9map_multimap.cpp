//
// Created by cheng on 12/13/18.
//
#include <map>
#include <iostream>

using namespace std;

int main()
{
    typedef multimap<int, double> mmid;
    mmid pairs;
    cout << pairs.count(15) << endl;
    pairs.insert(mmid::value_type(15, 222.7));
    pairs.insert(mmid::value_type(15, 99.7));
    cout << pairs.count(15) << endl;
    pairs.insert(mmid::value_type(30, 111.11));
    pairs.insert(mmid::value_type(10, 22.7));
    pairs.insert(mmid::value_type(25, 99.7));
    pairs.insert(mmid::value_type(20, 99.7));
    for(mmid::const_iterator i = pairs.begin();i!=pairs.end();i++)
        cout << "(" << i->first << "," << i->second << ")" << ",";
    return 0;
}
