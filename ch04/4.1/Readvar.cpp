#include <iostream>
#include <strstream>
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

int ReadVariablePerson(istream& stream, Person& p)
{
    // read a variable sized record from stream  and store it in p
    short length;
    stream.read((char *) &length, sizeof(length));
    // create buffer space
    char* buffer = new char[length+1];
    stream.read(buffer,length);
    buffer[length]=0;   // null terminate
    istrstream strbuff(buffer); // create a string stream
    strbuff >> p;   // use  istream extraction operator
    return 1;
}