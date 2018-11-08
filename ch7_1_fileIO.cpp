#include<iostream>
#include<fstream>
#include<cstring>
/// write from keyboard input to a binary

using namespace std;

class CStudent
{
public:
    char szName[20];
    int nScore;
};

int main()
{
    void read_binary(string);
    void io_binary(string);

    CStudent s;
    ofstream Out("./binaryfile.dat", ios::out|ios::binary);
    while(cin >> s.szName >> s.nScore)
    {
        if (!strcmp("exit", s.szName))
            {s.nScore = 0;break;}
        Out.write((char *) &s, sizeof(s));
    }
    Out.close();
    // read_binary("./binaryfile.dat");
    io_binary("./binaryfile.dat");
    /*ofstream fout("a1.out", ios::app);
	long location = fout.tellp();
	location = 10L;
	fout.seekp(location);
	fout.seekp(location, ios::beg);
	fout.seekp(location, ios::cur);
	fout.seekp(location, ios::end);*/
    return 0;
}

void read_binary(string fname)
{
    CStudent s;
    ifstream In(fname, ios::in|ios::binary);
    if(!In)
    {
        cerr << "Invalid file" <<endl;
        In.close();
        return;
    }
    while(In.read((char *) & s, sizeof(s)))
    {
        int counter = In.gcount();
        cout << s.szName << " " << s.nScore << endl;
    }
    In.close();
}

void io_binary(string fname)
{
    CStudent s;
    fstream IOfile(fname, ios::in|ios::out|ios::binary);
    if(!IOfile)
    {
        cerr << "IOfile: Invalid file" <<endl;
        IOfile.close();
        return;
    }
    IOfile.seekp(2*sizeof(s), ios::beg);  // set put-pointer at the 3rd place
    IOfile.write("Mike", sizeof("Mike")+1);
    IOfile.seekg(0, ios::beg);  // set get-pointer at the beginning
    while(IOfile.read((char *)&s, sizeof(s)))
        cout << s.szName << " " << s.nScore << endl;
    IOfile.close();
}
