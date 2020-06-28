#include "strlist.h"
#include "coseq.cpp"  // for tamplate

int main ()
{
	StringListProcess List(2);// declare process with 2 lists
	List.Match2Lists ("list1.txt","list2.txt","match.txt");
	List.Merge2Lists ("list1.txt","list2.txt","merge.txt");
	return 1;
}
