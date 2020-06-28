#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    String();                                   // default constructor
    String (const String&);                     // copy constructor
    String (const char*);                       // create from C String
    ~String();                                  // destructor
    String & operator = (const String& );       // assignment
    int operator ==  (const String& ) const;    // equality
    operator char*();                           //
    char * str() const;                         //  converstion to char*

    int setString(const char* str);
   
    friend ostream & operator << (ostream& stream, String& str);

private:
    char * string;                              // represent value as C string
    int MaxLength;    
};

