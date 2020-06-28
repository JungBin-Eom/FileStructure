#include <iostream>
#include <cstring>
#include "Person.h"

using namespace std;

istream & operator >> (istream & stream, Person & p)
{ 
    // read fields from file
	char delim;
	
	stream.getline(p.LastName, 30,'|');
	//cout << "Size of Last: " << strlen(p.LastName) << flush;
	if (strlen(p.LastName)==0) return stream; 
	stream.getline(p.FirstName,30,'|');
	stream.getline(p.Address,30,'|');
	stream.getline(p.City, 30,'|');
	stream.getline(p.State,15,'|');
	stream.getline(p.ZipCode,10,'|');	
	return stream;
}