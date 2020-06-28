#include "Person.h"

using namespace std;

int main()
{
    cout<<"<<<<< Testing Person class >>>>>>>>"<<endl;

    Person p;
    Person *p_ptr = new Person;

    cout<<"Print Person class"<< endl;
    cout<<"FirstName: "<< p_ptr->FirstName;
    cout<<"LastName: "<< p_ptr->LastName;
    cout<<endl;
}