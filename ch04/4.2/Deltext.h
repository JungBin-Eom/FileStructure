#ifndef DELTEXT_H
#define DELTEXT_H

#ifndef FALSE
#define FALSE (0)
#define TRUE (1)
#endif

#include <iostream>

using namespace std;

class DelimTextBuffer
{
public:
    // construct with fiedls with delimeters
    DelimTextBuffer (char Delim = '|', int maxBytes = 1000);
    void Clear();       // clear fields from buffer
    int Read (istream & file);
	int Write (ostream & file) const;
	int Pack (const char * str, int size = -1);
	int Unpack (char *str);
    int Init (char delim, int maxBytes = 1000);
	void Print (ostream &) const;
private:
	char Delim;	        //delimiter character
    char DelimStr[2];   // zeoro terminated string for Delim
	char * Buffer; 	    // character array to hold field values
	int BufferSize;     // current size of packed fields
	int MaxBytes;	    // max # of characters in buffer
	int NextByte;       //packing, unpacking position in buffer
};

#endif