const int MaxBufferSize = 200;
int WritePerson (ostream & stream, Person & p)
{
		char buffer [MaxBufferSize];
		strcpy(buffer, p.LastName); strcat(buffer, "|");
		// omitted
        strcat(buffer, p.State); strcat(buffer, "|");
		strcat(buffer, p.ZipCode); strcat(buffer, "|");
		short length = strlen(buffer);
		stream.write (&length, sizeof(length));
		stream.write (&buffer, length);
}
