// makeind.cc
#include "textind.h"
#include "buffile.h"
#include "delim.h"
#include "recording.h"
#include "recfile.h"
#include "./buf/recfile.cpp"  // for template method body
#include <iostream>

using namespace std;

int RetrieveRecording (Recording & recording, char * key, 
			TextIndex & RecordingIndex, BufferFile & RecordingFile)
// read and unpack the recording, return TRUE if succeeds
{	int result;
	cout <<"Retrieve "<<key<<" at recaddr "<<RecordingIndex.Search(key)<<endl;
	result = RecordingFile . Read (RecordingIndex.Search(key));
	cout <<"read result: "<<result<<endl;
	if (result == -1) return FALSE;
	result = recording.Unpack (RecordingFile.GetBuffer());
	return result;
}

// make an index from a recording file
int IndexRecordingFile (char * myfile, TextIndex & RecordingIndex)
{
	Recording rec; int recaddr, result;
	DelimFieldBuffer Buffer; // create a buffer
	BufferFile RecordingFile(Buffer); 
	result = RecordingFile.Open (myfile,ios::in);
	if (!result)
	{
		cout << "Unable to open file "<<myfile<<endl;
		return 0;
	}
	while (1) // loop until the read fails
	{
		recaddr = RecordingFile.Read (); // read next record
		if (recaddr < 0) break;
		rec. Unpack (Buffer);
		RecordingIndex . Insert(rec.Key(), recaddr);
		cout << recaddr <<'\t'<<rec<<endl;
	}
	RecordingIndex.Print (cout);
	result = RetrieveRecording (rec, "LON2312", RecordingIndex, RecordingFile);
	cout <<"Found record: "<<rec;
}

void CreateRecordingFile()
{
	int recaddr;
	DelimFieldBuffer Buffer;
	BufferFile RecordingFile (Buffer);
	RecordingFile.Create ("record.dat", ios::out);	
	Recording * R[10];
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
		R[i]->Pack (Buffer);
		recaddr = RecordingFile.Write();
		cout <<"Recording R["<<i<<"] at recaddr "<<recaddr<<endl;
		delete R[i];
	} 
}

int main (int argv, char ** argc)
{
	// first argument is the file name for the data file
	CreateRecordingFile();
	TextIndex RecordingIndex (10);
	IndexRecordingFile ("record.dat", RecordingIndex);
	
	// store the index in a file
	/*
	TextIndexBuffer IndexBuffer (12, 10);// 12 byte key, 10 keys
	BufferFile IndexFile (IndexBuffer);
	IndexBuffer.Pack(RecordingIndex);
	IndexFile . Create ("recindex.dat", ios::out);
	IndexFile . Write ();
	*/
	return -1;
}

