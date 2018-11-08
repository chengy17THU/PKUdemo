#include<iostream>
#include<iomanip>
/// IO-manipulation
/// individual functions are io-manipulators from <iomanip>

using namespace std;

int main()
{
    // set integer base number
    int n=10;
    cout << hex << n << endl
         << oct << n << endl
         << dec << n << endl;
    // set output valid numbers for float numbers
    double f=1.1917321;
    cout << f << endl; // 6 valid digits by default
    cout << setprecision(3) << f << endl;
    cout << setprecision(8) << f << endl;
    // cout.precision(3);
    double ff = 123456.789;
    cout << f << " " << ff << endl;
    cout << setiosflags(ios::fixed) << ff << "\n"
    << resetiosflags(ios::fixed) << ff << endl;
    // set width for IO
    int w = 4;
    char s[10];
    // cin.width(5);
    while(cin >> setw(5) >> s)
    {
        cout << s << "why only 4 digits, not 5??" << endl;
        // cout.width(w++);
        cout << setw(w++) <<s << endl;
        // cin.width(5);
    }
    cout << s << endl;
    // customized manipulators
    ostream &tab(ostream &);
    cout << f << tab << ff << endl;
    return 0;
}

ostream &tab(ostream &output)
{
    return output << '\t';
}
