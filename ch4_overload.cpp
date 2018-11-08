#include<iostream>
#include<cstdlib> // atof()
using namespace std;

class Complex
{
    double re;
    double im;
public:
    friend istream & operator>>(istream & is, Complex & c);
    Complex(double r=0, double i=0): re(r), im(i) {}
    double real() const {return re;}
    double image() const {return im;}
};

ostream & operator<<(ostream & os, const Complex c) // for const Complex, Complex::real() has to be const
{
    return os << c.real() << '+' << c.image() << 'i';
}

istream & operator>>(istream & is, Complex & c)
{
    string s;
    is >> s;
    // copied from video tutorial
    int pos = s.find("+",0);
    string sTmp = s.substr(0,pos);
    c.re = atof(sTmp.c_str());
    sTmp = s.substr(pos+1,s.length()-pos-2);
    c.im = atof(sTmp.c_str());
    return is;
}
int main()
{
    Complex c;
    // cout << c.real() << " " << c.image() << endl;
    int n=0;
    cin >> c >> n;
    cout << c.real()<<endl;
    cout << c << "," << n;
    return 0;
}
