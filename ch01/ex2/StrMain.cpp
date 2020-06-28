#include "Strclass.h"

//using namespace std;

int main()
{
    cout<<"=======String Class Test==========="<<endl;
    String s1("abcdefg");    // Q1: uses which fuction?
    char str[10];
    strcpy (str, s1);       //Q2: uses which funciton?
    
    String s2;
    s2 = s1;        // Q3: uses which function?

    cout << "s1:\t"<< s1 << endl;
    cout << "s2:\t"<< s2 << endl;
    cout << "After setString" << endl;
    s1.setString("newStr");
    cout << "s1:\t"<< s1 << endl;
    cout << "s2:\t"<< s2 << endl;
   
    int c1=strcmp(s1, s2);     // Q4: why this code works?
    cout<<"comp: " << c1 << endl;

    String s3(s1);   // Q5: uses which function?

    String* s4 = new String;
    *s4 = s3;       // Q6: uses which function?
        
    cout << "s3:\t"<< s3 << endl;
    cout << "s4:\t"<< *s4 << endl;        // Q7: why use *s4?
    
    return 0;
}