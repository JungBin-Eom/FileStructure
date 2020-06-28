Person maryAmes;
DelimTextBuffer buffer; //FixedFieldBuffer buffer;
buffer.pack(MaryAmes.lastName);
buffer.pack(MaryAmes.FirstName);
...
buffer.pack (MaryAmes.zipcode);
buffer.write(stream);

class istream: virtual public ios {  . . .
class ostream: virtual public ios {  . . .
class iostream: public istream, public ostream { . . .
class ifstream: public fstreambase, public istream {  . . .
class ofstream: public fstreambase, public ostream { . . .
class fstream: public fstreambase, public iostream { . . .

int ReadVariablePerson (istream & stream, Person & p)
{
		. . .
		istrstream strbuff (buffer);	//create a string stream
		strbuff >> p; //use the istream extraction operator
		return 1;
}

class IOBuffer
{ 
public:
    IOBuffer (int maxBytes = 1000);
    virtual int Read (istream &) = 0; //read a buffer
    virtual int Write (ostream &) const = 0; //write a buffer
    virtual int Pack(const void * field, int size = -1) = 0;
    virtual int Unpack (void * field,int maxbytes = -1) = 0;
protected:
    char * Buffer; //character array to hold field values
    int BufferrSize; // sum of the sizes of packed fields
    int MaxBytes; //max # of char in the buffer
};

class VariableLengthBuffer: public IOBuffer
{ 
public:
   VariableLengthBuffer (int MaxBytes = 1000);
   int Read (istream &);
   int Write (ostream &) const;
   int SizeOfBuffer () const;
}; 

class DelimFieldBuffer: public VariableLengthBuffer
{ public:
	DelimFieldBuffer (char Delim = -1, int maxBytes = 1000);
	int Pack (const void *, int size = -1);
	int Unpack (void *field, int maxBytes = -1);
protected:
	char Delim;
};

