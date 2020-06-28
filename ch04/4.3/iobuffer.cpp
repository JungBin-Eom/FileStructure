// iobuffer.cpp
#include "iobuffer.h"
#include <cstring>

IOBuffer::IOBuffer (int maxBytes)
// construct with a maximum of maxFields
{
	Init (maxBytes);
}

int IOBuffer::Init (int maxBytes)
{
	Initialized = FALSE;
	if (maxBytes < 0) maxBytes = 0;
	MaxBytes = maxBytes;
	Buffer = new char[MaxBytes];
	BufferSize = 0;
	Clear ();
	return 1;
}

void IOBuffer::Clear ()
// clear field values from buffer
{
	NextByte = 0;
	Packing = TRUE;
}

void IOBuffer::Print (ostream & stream) const
{
	stream<<"MaxBytes "<<MaxBytes<<" BufferSize "<<BufferSize;
}
