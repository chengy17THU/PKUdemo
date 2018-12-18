//
// Created by cheng on 12/13/18.
//
#include <map>
#include <string>
#include <iostream>

using namespace std;

class CStudent
{
public:
    struct CInfo
    {
        int id;
        string name;
    };
    int score;
    CInfo info;
};

typedef multimap<int, CStudent::CInfo> MAP_STU;

int main()
{
    // 1. basic demo
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
    // 2. example
    MAP_STU mp;
    CStudent st;
    string cmd; // command line input, case-sensitive
    while(cin >> cmd)
    {
        if(cmd=="Add")
        {
            cin >> st.info.name >> st.info.id >> st.score;
            // mp.insert(MAP_STU::value_type(st.score, st.info));
            mp.insert(make_pair(st.score, st.info));
        } else if (cmd=="Query")
        {
            int score;
            cin >> score;
            MAP_STU::iterator p=mp.lower_bound(score);
            if(p!=mp.begin())
            {
                --p;
                score = p->first;
                MAP_STU::iterator maxp = p; // record best-match
                int maxID = p->second.id; // id of best-match
                for(;p!=mp.begin()&&p->first==score;--p)
                {
                    if(p->second.id>maxID)
                    {
                        maxp = p;
                        maxID =p->second.id;
                    }
                }
                if(p->first == score)
                {
                    if(p->second.id > maxID)
                    {
                        maxp = p;
                        maxID = p->second.id;
                    }
                }
                cout << maxp->second.name << " " << maxp->second.id << " " << maxp->first << endl;
            }
            else
                cout << "Nobody" << endl;
        }
    }
    // 3. use of map
    return 0;
}
