#include <fstream>
#include <cstring>
#include <iostream>
#include "Person.h"

using namespace std;

//forward declaration, defined in Readper.cpp
istream& operator >> (istream& stream, Person& p);
// forward declaration, defined in Writestr.cpp
ostream& operator<<(ostream& stream, Person& p);

int main()
{
    char filename[20];
    Person p;
    cout << "Enter the file name: " << flush;
    cin.getline(filename, 19);
    // Note, filestream is used
    ofstream stream(filename, ios::out);
    if(stream.fail())
    {
        cout << "File open failed!" << endl;
        return -1;
    }
    while(1)
    {
        cin >> p;       // read fields of person
        if (strlen(p.LastName) ==0) break;
        // write person to output stream
        stream << p;    // write fields of person
    }
    
    return 0;
}