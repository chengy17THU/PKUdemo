#include<iostream>
#include<fstream>
#include<cstring>
/// copy contents from 1 existing binary to another

using namespace std;

int main(int argc, char *argv[])
{
    // command-line arguments:
    // argc is number of commands, argv is a list of commands
    if(argc!=3)
    {
        // 3 commands: exe, infile, outfile
        cerr << "Invalid command-line options1" << endl;
    }
    ifstream inFile(argv[1], ios::binary|ios::in);
    if(!inFile)
    {
        cout << "Invalid file open" << endl;
        inFile.close();
        return 0;
    }
    ofstream outFile(argv[2], ios::binary|ios::out);
    if(!outFile)
    {
        cout << "Invalid file open" << endl;
        inFile.close();
        outFile.close();
        return 0;
    }
    char c;
    while(inFile.get(c))
        outFile.put(c); // write 1 char at a time
    outFile.close();
    inFile.close();
    return 0;
}
