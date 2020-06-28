#include "Strclass.h"

String::String()
{
    string =0;
    MaxLength = 0;
}

String::~String()
{
    if (string != 0)    delete string;
    MaxLength = 0;
    string = 0;
}


int String::setString(const char* str)         // create from C String
{
    int newlen = strlen(str);
    if ( MaxLength < newlen)
    {
        cout << "new string is too large"<< endl;
        return -1;
    } 
    // string = new char[MaxLength];
    strcpy(string, str);  
    return 0;
}


ostream & operator<< (ostream& stream, String &str)
{
    stream << str.string;
    return stream;
}


// copy consructor
String::String (const String& str)      
{
    string = strdup( str.string);
    MaxLength = strlen(string);
}

String::String(const char* str)         // create from C String
{
    string = strdup(str);
    MaxLength = strlen(string);
}


// assignment
String& String::operator= (const String & str) 
{
    if (strlen (str.string) >= MaxLength)
    {
        delete string;
        string = strdup(str.string);
        MaxLength = strlen(string);
    }
    strcpy (string, str.string);
    return *this;
}

String::operator char*()
{
    return strdup(string);
}

int String::operator== (const String& str) const
{
    return strcmp (string, str.string) == 0;
}

char* String::str() const           // return a copy of the string
{
    return strdup(string);
}

