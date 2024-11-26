#include <iostream>
#include <string.h>
#include <stdio.h>

enum FileOpResult {Success, Failure};
FileOpResult write_to_file(const char *name, char *content);
FileOpResult copy_file(const char *file_from, const char *file_to);
void print_data(const char* name);

int main()
{
    const char* file_name1 = "filename1.txt";
    const char* file_name2 = "filename2.txt";
    int size_of_content = 256;
    char content[size_of_content];
    std::cout << "Enter a string to be written in a file: " << std::endl;
    std::cin.getline(content, size_of_content);

    if(write_to_file(file_name1, content) == Failure)
        std::cout << "Failed to write content to file" << std::endl;
    else
        std::cout << "Content was successfully written!" << std::endl;

    if(copy_file(file_name1, file_name2) == Failure)
        std::cout << "Failed to copy content to file" << std::endl;
    else
        std::cout << "Content was successfully coppied!" << std::endl;
        
    return 0;
}

FileOpResult write_to_file(const char *name, char *content)
{
    if(name == nullptr || strlen(name) == 0)
        return Failure;

    FILE* fptr = fopen(name, "w");
    if(fptr == NULL)
        return Failure;
    
    fwrite(content, sizeof(char), strlen(content), fptr);

    if(fclose(fptr) != 0)
        return Failure;
    return Success;
}


FileOpResult copy_file(const char *file_from, const char *file_to)
{    
    if(file_from == nullptr || strlen(file_from) == 0 || file_to == nullptr || strlen(file_to) == 0)
        return Failure;
    
    FILE* fptr1 = fopen(file_from, "r");
    FILE* fptr2 = fopen(file_to, "w");

    if (fptr1 == NULL || fptr2 == NULL)
        return Failure;
    
    char buffer[256];
    while((fgets(buffer, sizeof(buffer), fptr1)) != NULL)
    {
        if(fputs(buffer, fptr2) == EOF)
        {
            fclose(fptr1);
            fclose(fptr2);
            return Failure;
        }
    }
    if (fclose(fptr1)!=0 || fclose(fptr2)!= 0)
        return Failure;
    return Success;
}

void print_data(const char* name)
{
    FILE* fptr = fopen(name, "r");
    if(fptr == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
    char ch;
    while((ch = fgetc(fptr)) != EOF)
        putchar(ch);
    fclose(fptr);
}