#include <cstring>
#include <iostream>
#include <fstream>
#include <limits>
#include "HW2.h"

using namespace std;

istream& operator >> (istream& stream, Student& s);
ostream& operator << (ostream& stream, Student& s);

int main(void)
{
	cout << "-------Student Management Program with File(delimiters)--------" << endl;
	char filename[20];
	char menuNum[2];
	while(1){
		cout << flush;
		cout << "Select Menu [ 1:write | 2:read | 3:Exit ] >> " << flush;
		cin.getline(menuNum, 2);
		if(menuNum[0] == '1'){
			Student s;
			cout << "Enter the file name >> " << flush;
			cin.getline(filename, 19);
			//cin >> filename;
    		ofstream outfile(filename, ios::out);
			if(outfile.fail()){
				cout << "File open failed!" << endl;
				return -1;
			}
	
			while (1){
				cout << "[Enter the input as the following format]" << endl;
				cout << "Student Number|Name|Address|Date|" << endl;
				cin >> s;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if(strlen(s.StudentNumber) == 0) break;
				outfile << s;
			}
			outfile.close();
		}
		else if(menuNum[0] == '2'){
			Student s;
			cout << "Enter the file name >> " << flush;
			cin.getline(filename, 19);
			ifstream infile(filename, ios::in);	
			if(infile.fail()){
	        	cout << "File open failed!" << endl;
            	return -1; 
	        }	
  
			while(1) {
				infile >> s;
				if(strlen(s.Name) == 0) break;
				cout << s << endl;
			}	
			infile.close();
		}
		else if(menuNum[0] == '3'){
			break;
		}
	}
	return 0;
}
