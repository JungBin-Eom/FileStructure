#include <iostream>
#include "Person.h"

using namespace std;

ostream& operator<<(ostream& stream, Person& p)
{
    // insert fields into file
    stream << p.LastName << p.FirstName << p.Address
        << p.City << p.State << p.ZipCode;
    return stream;
}

