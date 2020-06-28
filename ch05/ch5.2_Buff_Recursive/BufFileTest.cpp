#include <fstream>
#include <iomanip>
#include <cstring>
#include "iobuffer.h"
#include "fixfld.h"
#include "length.h"
#include "person.h"
#include "buffile.h"

Person MaryAmes;
Person AlanMason;
Person JKwon;

void InitPerson()
{
	cout << "Initializing 3 Persons"<<endl;
	strcpy(MaryAmes.LastName, "Ames");
	strcpy(MaryAmes.FirstName, "Mary");
	strcpy(MaryAmes.Address, "123 Maple");
	strcpy(MaryAmes.City, "Stillwater");
	strcpy(MaryAmes.State, "OK");
	strcpy(MaryAmes.ZipCode, "74075");
	MaryAmes.Print (cout);
	strcpy(AlanMason.LastName, "Mason");
	strcpy(AlanMason.FirstName, "Alan");
	strcpy(AlanMason.Address, "90 Eastgate");
	strcpy(AlanMason.City, "Ada");
	strcpy(AlanMason.State, "OK");
	strcpy(AlanMason.ZipCode, "74820");
	AlanMason.Print (cout);
    strcpy (JKwon.LastName, "Kwon");
	strcpy (JKwon.FirstName, "J");
	strcpy (JKwon.Address, "416");
	strcpy (JKwon.City, "Busan");
	strcpy (JKwon.State, "Bu");
	strcpy (JKwon.ZipCode, "416");
    JKwon.Print (cout);
}


void testBuffer (IOBuffer & Buff, char * myfile)
{
	Person person;
	int result;
	int recaddr1, recaddr2, recaddr3, recaddr4;

	// Test writing
	//Buff . Print (cout);
	ofstream TestOut (myfile,ios::out);
	result = Buff . WriteHeader (TestOut);
	cout << "write header "<<result<<endl;
	MaryAmes.Pack (Buff);
	//Buff . Print (cout);
	recaddr1 = Buff.Write (TestOut);
	cout << "write at "<<recaddr1<<endl;
    JKwon.Pack(Buff);
    recaddr2 = Buff.Write (TestOut);
	cout << "write at "<<recaddr2<<endl;
	AlanMason.Pack (Buff);
	//Buff.Print (cout);
	recaddr3 = Buff.Write (TestOut);
	cout << "write at "<<recaddr3<<endl;
    TestOut.close ();

	// test reading
	ifstream TestIn (myfile, ios::in);
	result = Buff.ReadHeader (TestIn);
	cout <<"read header "<<result<<endl;
	Buff.DRead (TestIn, recaddr3);
    //Buff.Read(TestIn);
	person.Unpack (Buff);
	person.Print(cout, "Third record:");
	Buff.DRead (TestIn, recaddr1);
    //Buff.Read(TestIn);
	person.Unpack (Buff);
	person.Print(cout, "First record:");
	Buff.DRead(TestIn, recaddr2);
    //Buff.Read(TestIn);
	person.Unpack (Buff);
	person.Print (cout, "Second record:");
}

void testBufferFile (IOBuffer & Buff, char * myfile)
{
	Person person;
	int result;
	int recaddr1, recaddr2, recaddr3, recaddr4;

	// Test writing
	//Buff . Print (cout);
	BufferFile TestOut (Buff);
	// Note that header information is also written
	result = TestOut.Create (myfile, ios::in|ios::out);
	cout << "create file "<<result<<endl;
	if (!result)
	{
		cout << "Unable to create file "<<myfile<<endl;
		return;
	}
	MaryAmes.Pack (TestOut.GetBuffer());
	recaddr1 = TestOut.Write();
	//recaddr1 = Buff.Write (TestOut);
	cout << "write at "<<recaddr1<<endl;
	JKwon.Pack (TestOut.GetBuffer());
 	recaddr2 = TestOut.Write();
    //recaddr2 = Buff.Write (TestOut);
	cout << "write at "<<recaddr2<<endl;
	AlanMason.Pack (TestOut.GetBuffer());
	recaddr3 = TestOut.Write();
	//recaddr3 = Buff.Write (TestOut);
	cout << "write at "<<recaddr3<<endl;
    TestOut.Close ();

	// test reading
	BufferFile TestIn (Buff);
	// Note that header information is also obtained when we call Open()
	TestIn.Open (myfile, ios::in);

	TestIn.Read(recaddr3);
	//Buff.DRead (TestIn, recaddr3);
    //Buff.Read(TestIn);
	person.Unpack (TestIn.GetBuffer());
	//person.Unpack (Buff);
	person.Print(cout, "Third record:");

	TestIn.Read (recaddr1);
	//Buff.DRead (TestIn, recaddr1);
    //Buff.Read(TestIn);
	person.Unpack (TestIn.GetBuffer());
	//person.Unpack (Buff);
	person.Print(cout, "First record:");

	TestIn.Read (recaddr2);
	//Buff.DRead(TestIn, recaddr2);
	//Buff.Read(TestIn);
	person.Unpack (TestIn.GetBuffer());
	//person.Unpack (Buff);
	person.Print (cout, "Second record:");
	TestIn.Close();
}



void testFixedField ()
{
	cout <<"Testing Fixed Field Buffer"<<endl;
	FixedFieldBuffer Buff (6);
	Person :: InitBuffer (Buff);
	//testBuffer (Buff, "fixlen.dat");
	testBufferFile(Buff, "fixlen2.dat");
}


void testLength ()
{
	cout << "\nTesting LengthTextBuffer"<<endl;
	LengthFieldBuffer Buff;
	Person :: InitBuffer (Buff);
	//testBuffer (Buff, "length.dat");
	testBufferFile(Buff, "length2.dat");
}


void testDelim ()
{
	cout << "\nTesting DelimTextBuffer"<<endl;
	DelimFieldBuffer::SetDefaultDelim ('|');
	DelimFieldBuffer Buff;
	Person :: InitBuffer (Buff);
	//testBuffer(Buff, "delim.dat");
	testBufferFile(Buff, "delim2.dat");
}

int main(int argc, char ** argv)
{
	InitPerson();
	testFixedField ();
	testLength ();
	testDelim ();
}