#include <fstream>
#include <cstring>
#include <iostream>
#include<limits>  // for numeric_limits 
#include "Person.h"

using namespace std;

//forward declaration, defined in Readdel.cpp
istream& operator >> (istream& stream, Person& p);
// forward declaration, defined in Writedel.cpp
ostream & operator << (ostream & stream, Person & p);

int main()
{
    cout<<"<<<<<<< Records with delimiters >>>>>>>>>"<<endl;
    char filename [20];
	Person p;
	cout << "Enter the output file name:"<<flush;
	cin.getline(filename, 19);
	ofstream outfile (filename, ios::out);
	if (outfile.fail()) {
		cout << "File open failed!" <<endl;
		return 0;
	}

        
	while (1) {
		// read fields of person
		cout << "Provide the input as the following format:" << endl;
		cout << "Last|First|Addr|City|State|Zip|"<<endl;
		cin >> p;
        // discards the input buffer 
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
        cout << "Strlen of LastName: " << strlen(p.LastName) << endl;
        
		if (strlen(p.LastName)==0) break;
		// write person to file
        // cout << p << flush;
		// cout<< endl;
		outfile << p;
	}
	outfile.close();

	cout<<"<<<<<<< Read delimitered records from a file >>>>>>>>>"<<endl;
	ifstream infile(filename, ios::in);

	while (1) {
		// read fields of person from a file
		infile >> p;
		if (strlen(p.LastName)==0) break;
		// display Person records to stdout
		cout << p << endl;
	}
	infile.close();
   
    return 0;
}