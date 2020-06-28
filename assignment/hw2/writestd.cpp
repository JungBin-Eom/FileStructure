#include <iostream>
#include "HW2.h"

using namespace std;

ostream & operator << (ostream& stream, Student &s)
{
	stream << s.StudentNumber << '|' << s.Name << '|'
			<< s.Address << '|' << s.Date << '|' << s.Credit << '|';
	return stream;
}
