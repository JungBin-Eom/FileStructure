#include <iostream>
#include <fstream>

using namespace std;

void error(char *s, char *s2 = ""){
	cerr << s << ' ' << s2 << '\n'; 
	exit(1);
}

int main(int argc, char *argv[])
{
	if( argc != 3) error("wrong number of arguments");

	ifstream src(argv[1]);   //input file stream
	if (!src) error("cannot open input file", argv[1]);
    ofstream dest(argv[2]);    //output file stream
	if(!dest) error("cannot open output file", argv[2]);

	char ch;
	while( src.get(ch) ) dest.put(ch);
	
	if(!src.eof() || dest.bad()) 
		error("something strange happened");
	return 0;
}