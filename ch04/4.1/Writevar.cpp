#include <iostream>
#include <cstring>
#include "Person.h"

using namespace std;

ostream & operator << (ostream & stream, Person & p)
{ 
    // insert fields into file
	stream << p.LastName <<'|'<< p.FirstName <<'|'
		<< p.Address << '|' << p.City << '|'
		<< p.State <<'|' << p.ZipCode << '|';
	return stream;
}


const int MaxBufferSize = 200;
int WriteVariablePerson (ostream & stream, Person & p)
{	
	// create buffer of fixed size
	char buffer [MaxBufferSize];
	strcpy(buffer, p.LastName); strcat(buffer,"|");
	strcat(buffer, p.FirstName); strcat(buffer,"|");
	strcat(buffer, p.Address);  strcat(buffer,"|");
	strcat(buffer, p.City);  strcat(buffer,"|");
	strcat(buffer, p.State);  strcat(buffer,"|");
	strcat(buffer, p.ZipCode);  strcat(buffer,"|");
	short length=strlen(buffer); 
	stream.write ((char *)&length, sizeof(length)); // write length
	stream.write ((char *)&buffer, length);

	return 0;
}
