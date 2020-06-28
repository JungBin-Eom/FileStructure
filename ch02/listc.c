#include <stdio.h>

int main()
{
    char ch;
    FILE *file;         //  pointer to file descriptor
    char filename[20];
    printf("Enter the name of the file: ");     // step1
    gets(filename);                             // step2
    file = fopen(filename, "r");                // step3
    while ( fread (&ch, 1, 1, file) != 0)       // step 4a
        fwrite(&ch, 1, 1, stdout);              // step 4b
    fclose(file);                               // step 5
    return 0;
    
}