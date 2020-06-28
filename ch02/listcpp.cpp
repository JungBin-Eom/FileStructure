#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    fstream file;         //  declare unattached fstream
    char filename[20];
    cout<< "Enter the name of the file: "       // step1
        << flush;               // fource output
    cin>>filename;                              // step2
    file.open(filename, ios::in);               // step3
    // include white space in read
    file.unsetf(ios::skipws);
    while (1)
    {
        file >> ch;                             // step 4a
        if (file.fail()) break;
        cout << ch;                             // step 4b
    }       
    file.close();                               // step 5
    return 0;    
}