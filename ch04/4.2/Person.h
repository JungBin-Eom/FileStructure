#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Deltext.h"
#include "Fixtext.h"
#include "Lentext.h"

using namespace std;

class Person
{
public:
    // data members;
    char LastName[11];
    char FirstName[11];
    char Address[16];
    char City[16];
    char State[3];
    char ZipCode[10];
    //operations
    Person ();
    void Clear ();
	static int InitBuffer (LengthTextBuffer &);
	int Unpack (LengthTextBuffer &);
	int Pack (LengthTextBuffer &) const;
	
    static int InitBuffer (DelimTextBuffer &);
	int Unpack (DelimTextBuffer &);
	int Pack (DelimTextBuffer &) const;
    
    static int InitBuffer (FixedTextBuffer &);
	int Unpack (FixedTextBuffer &);
	int Pack (FixedTextBuffer &) const;
	void Print (ostream &);
};


#endif
