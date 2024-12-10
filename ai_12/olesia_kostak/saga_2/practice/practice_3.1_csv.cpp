#include <stdio.h>
#include <stdlib.h>

const int SIZE = 256;
void write_csv(const char *file_name, const char* data);
void read_csv(const char *filename);


int main() 
{
    const char* filename = "filename.csv";

    const char* data_to_write = "Hello,bro,how,are\nyou,doing,?";
    write_csv(filename, data_to_write);

    printf("Reading from %s:\n", filename);
    read_csv(filename);

    return 0;
}

void write_csv(const char *file_name, const char* data) 
{
    FILE *fptr = fopen(file_name, "w");
    if (fptr == nullptr) 
    {
        perror("Error opening file");
        exit(1);
    }

    fprintf(fptr, "%s", data);
    fclose(fptr);
}



void read_csv(const char *file_name) 
{
    FILE *fptr = fopen(file_name, "r");
    if (fptr == nullptr) 
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[SIZE];
    while (fgets(buffer, sizeof(buffer), fptr))
    {
        for (int i = 0; buffer[i] != '\0'; i++) 
        { 
            if (buffer[i] == ',') 
                buffer[i] = ' '; 
        }
        printf("%s", buffer);
    } 

    fclose(fptr);
}

