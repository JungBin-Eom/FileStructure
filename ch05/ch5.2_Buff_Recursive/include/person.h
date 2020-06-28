#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "fixfld.h"
#include "delim.h"
#include "length.h"

class Person 
{
  public:
	// fields
	char LastName [11];
	char FirstName [11];
	char Address [16];
	char City [16];
	char State [3];
	char ZipCode [10];

	//operations
	Person ();
	void Clear ();

	static int InitBuffer (DelimFieldBuffer &);
	static int InitBuffer (LengthFieldBuffer &);
	static int InitBuffer (FixedFieldBuffer &);

	int Unpack (IOBuffer &);
	int Pack (IOBuffer &) const;
	void Print (ostream &, char * label = 0) const;
};

#endif
