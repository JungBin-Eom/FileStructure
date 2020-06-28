#include <iostream>
#include <cstring>
#include "HW2.h"

using namespace std;

istream & operator >> (istream & stream, Student& s)
{
	char delim;
	
	stream.getline(s.StudentNumber, 30, '|');
	if(strlen(s.StudentNumber) == 0) return stream;
	stream.getline(s.Name, 30, '|');
	stream.getline(s.Address, 30, '|');
	stream.getline(s.Date, 30, '|');
	return stream;
}
