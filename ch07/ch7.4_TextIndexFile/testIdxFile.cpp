// maketxtindxfile.cpp

// Headeers for template index
#include "textind.h"
#include "delim.h"
#include "buffile.h"
#include "recording.h"
#include "fixfld.h"
#include "indfile.h"
#include "./index/indfile.cpp"  // for template method body
#include <iostream>


using namespace std;


// make an indexed file from a recording file
// make an indexed file from a recording file
int ReadIndexRecordingFile (char* myfile, TextIndexedFile<Recording> & indexFile)
{
	Recording fileRec; 
	Recording indRec;
	int recaddr, result;
	DelimFieldBuffer Buffer; // create a buffer
	BufferFile RecFile(Buffer); 

	// open recordFile using the filename
	result = RecFile . Open (myfile,ios::in);
	if (!result)
	{
		cout << "Unable to open file "<<myfile<<endl;
		return 0;
	}
	while (1) // loop until the read fails
	{
		recaddr = RecFile . Read (); // read next record
		if (recaddr < 0) break;
		fileRec. Unpack (Buffer);
		cout <<"\nLooking for record with key:"
			<<fileRec.Key()<<endl;
		result=indexFile . Read(fileRec.Key(),indRec);
		if (result<0) cout <<"record not found";
		else indRec.Print(cout);
	}

}

void AddRecords(TextIndexedFile<Recording> & indexFile)
{
	int recaddr;
	Recording * R[10];
	Recording rec;	
	R[0] = new Recording ("LON", "2312", "Romeo and Juliet", "Prokofiev", "Maazel");
	R[1] = new Recording ("RCA", "2626", "Quartet in C Sharp Minor", "Beethoven", "Julliard");	
	R[2] = new Recording ("WAR", "23699", "Touchstone", "Corea", "Corea");
	R[3] = new Recording ("ANG", "3795", "Symphony No. 9", "Beethoven", "Giulini");
	R[4] = new Recording ("COL", "38358", "Nebraska", "Springsteen", "Springsteen");
	R[5] = new Recording ("DG", "18807", "Symphony No. 9", "Beethoven", "Karajan");
	R[6] = new Recording ("MER", "75016", "Coq d'or Suite", "Rimsky-Korsakov", "Leinsdorf");
	R[7] = new Recording ("COL", "31809", "Symphony No. 9", "Dvorak", "Bernstein");
	R[8] = new Recording ("DG", "139201", "Violin Concerto", "Beethoven", "Ferras");
	R[9] = new Recording ("FF", "245", "Good News", "Sweet Honey in the Rock", "Sweet Honey in the Rock");
	for (int i= 0; i<10; i++)
	{
		R[i]->Print(cout,"test");
		cout<< endl;
		recaddr = indexFile.Append(*R[i]);
		cout <<"Recording R["<<i<<"] at recaddr "<<recaddr<<" is added to TextIndexFile"<<endl;
		
		delete R[i];
	} 
}


int main (int argv, char ** argc)
{
	// create Record file.
	
	//char *recIdxFileName = "recindex.dat";
	//CreateRecordingFile(recFileName);
	char *strRecording = "recording";
	char *myfile="recording.dat";
	int result;

	TextIndex RecIndex (10);
	DelimFieldBuffer Buffer; // create a buffer
	TextIndexedFile<Recording> IndFile (Buffer, 12, 10);
	result = IndFile . Create(strRecording);
	if (!result) 
	{
		cout<<"Unable to create indfile "<<result<<endl;
		return 0;
	}	
	AddRecords(IndFile);

	Recording indRec;
	cout<<"Search Test1"<<endl;
	char* key1 = "COL3189";
	result=IndFile.Read(key1,indRec);
	if (result<0) cout <<"record not found"<<endl;
	else indRec.Print(cout);
	cout<<"Search Test2"<<endl;
	char* key2 = "MER75016";
	result=IndFile.Read(key2,indRec);
	if (result<0) cout <<"record not found";
	else indRec.Print(cout);
	
	/*
	ReadIndexRecordingFile (myfile, IndFile);
	*/
	IndFile.Close();

	return -1;
}

