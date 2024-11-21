#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


enum FileOpResult 
{ 
    Success, 
    Failure 
};


FileOpResult write_to_file(const char *name, const char *content);
FileOpResult copy_file(const char *file_from, const char *file_to);

int main()
{
    const char* filename1 = "file1.txt";
    const char* filename2 = "file2.txt";
    char content[256];

    cout << "enter a content(line)\n ";
    cin.getline(content, sizeof(content));

    FileOpResult result1 = write_to_file(filename1, content);
    if (result1 == Success) {
        cout << "Success. File created." << endl;
    } else {
        cout << "Failure. File could not be created." << endl;
    }

    FileOpResult result2 = copy_file(filename1, filename2);
    if (result2 == Success) {
        cout << "Success. File is copied." << endl;
    } else {
        cout << "Failure coping file." << endl;
    }
}

FileOpResult write_to_file(const char *name, const char *content)
{
    if (name == nullptr || strlen(name) == 0) {
        return FileOpResult::Failure;
    }

    FILE* f = fopen(name, "w");
    if (f == NULL) {
        return FileOpResult::Failure;
    }

    int len = strlen(content);
    size_t written = fwrite(content, sizeof(char), len, f);

    if (written != len) {
        fclose(f);
        return FileOpResult::Failure;
    }

    if (fclose(f) != 0) {
        return FileOpResult::Failure;
    }

    return FileOpResult::Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    if (file_from == nullptr || strlen(file_from) == 0 || file_to == nullptr || strlen(file_to) == 0) 
    {
        return FileOpResult::Failure;
    }

    FILE* f1 = fopen(file_from, "r");
    FILE* f2 = fopen(file_to, "w");

    if (f1 == NULL || f2 == NULL) 
    {
        return FileOpResult::Failure;
    }

    char buffer[512];
    while(fgets(buffer, sizeof(buffer), f1) != NULL)
    {
        if(fputs(buffer, f2) == EOF){
            fclose(f1);
            fclose(f2);
            return FileOpResult::Failure;
        }
    }

    if (fclose(f1) != 0 || fclose(f2) != 0) 
    {
        return FileOpResult::Failure;
    }

    return FileOpResult::Success;
}