ofstream myfile;
myfile.open ("example.bin", ios::out | ios::app | ios::binary); 


ofstream myfile ("example.bin", ios::out | ios::app | ios::binary);

file.seekg(373, ios::beg);
file.seekp(373, ios::beg);