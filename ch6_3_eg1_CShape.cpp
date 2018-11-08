#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

class CShape
{
public:
    // both are pure virtual
    virtual double Area()=0;
    virtual void PrintInfo()=0;
};

class CRect:public CShape
{
public:
    int w, h;
    virtual double Area();
    virtual void PrintInfo() {cout << "Rectangle, area is: " << Area() << endl;};
};

double CRect::Area()
{
    return w*h;
}

class CCircle:public CShape
{
public:
    int r;
    virtual double Area();
    virtual void PrintInfo() {cout << "Circle, area is: " << Area() << endl;};;
};

double CCircle::Area()
{
    return 3.1415926*r*r;
}

class CTrian:public CShape
{
public:
    int a, b, c;
    virtual double Area();
    virtual void PrintInfo() {cout << "Triangle, area is: " << Area() << endl;};;
};

double CTrian::Area()
{
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

CShape * pShapes[100]; // an array of class CShape pointers
int MyCompare(const void *s1, const void *s2)
{
    // s1 and s2 are pointing at element of array pShapes, i.e. at CShape pointers
    double a1, a2;
    CShape ** p1;
    CShape ** p2;
    p1 = (CShape **) s1;
    p2 = (CShape **) s2;
    a1 = (*p1)->Area();
    a2 = (*p2)->Area();
    if(a1 < a2)
        return -1;
    else if(a2 < a1)
        return 1;
    else
        return 0;
}

int main()
{
    int i, n;
    CRect * pr;
    CCircle * pc;
    CTrian * pt;
    cin >> n;
    for(i=0;i<n;i++)
    {
        char c;
        cin >> c;
        switch(c)
        {
        case 'r':
            pr = new CRect();
            cin >> pr->w >> pr->h;
            pShapes[i] = pr;
            break;
        case 'c':
            pc = new CCircle();
            cin >> pc->r;
            pShapes[i] = pc;
            break;
        case 't':
            pt = new CTrian();
            cin >> pt->a >> pt->b >> pt->c;
            pShapes[i] = pt;
            break;
        }
    }
    qsort(pShapes, n, sizeof(CShape*), MyCompare);
    for(i=0;i<n;i++)
        pShapes[i]->PrintInfo();
    return 0;
}
