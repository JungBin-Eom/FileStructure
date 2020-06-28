Person maryAmes;
DelimTextBuffer buffer; //FixedFieldBuffer buffer;
buffer.pack(MaryAmes.lastName);
buffer.pack(MaryAmes.FirstName);
...
buffer.pack (MaryAmes.zipcode);
buffer.write(stream);


DelimTextBuffer buffer; //default arguments
DelimTextBuffer buffer('|', 1000);

Person MaryAmes;
DelimFieldBuffer Buffer;
MaryAmes.Unpack (Buffer);

FixedFieldBuffer Buffer(6, 61);
MaryAmes.InitBuffer (Buffer);


DelimFieldBuffer buffer;
BufferFile file (buffer);
file.Open(myfile);
file.Read();
buffer.Unpack(myobject); 




DelimFieldBuffer buffer;
BufferFile file (buffer);
file.Create(“record.dat”, ios::out);//Page 640
person.Pack(Buffer);
file.Write(); //call Buffer.Write (File) see the page 632
             // then stream.Write(Buffer, BufferSize) 622
