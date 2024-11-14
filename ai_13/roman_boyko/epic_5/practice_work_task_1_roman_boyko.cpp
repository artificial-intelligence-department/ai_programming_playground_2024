#include <iostream>
#include <cstring>
using namespace std;
enum FileOpResult
{
    Success,
    Failure
};
FileOpResult write_to_file(char *name, char *content);
int main()
{
    char name[100];
    char st[250];
    cout << "Enter name of the file: ";
    cin.getline(name, 100);
    cout << "Enter some text: ";
    cin.getline(st, 250);

    FileOpResult f = write_to_file(name, st);
    if (f == Success)
    {
        cout << "Success" << endl;
    }
    else if (f == Failure)
    {
        cout << "Failure" << endl;
    }
}
FileOpResult write_to_file(char *name, char *content)
{

    FILE *fileStream = fopen(name, "w");
    if (fileStream != nullptr)
    {
        size_t write = fwrite(content, sizeof(char), strlen(content), fileStream);
        fclose(fileStream);
        if (write != strlen(content))
        {
            fclose(fileStream);
            return Failure;
        }
        fclose(fileStream);
    }
    else
    {
        return Failure;
    }

    return Success;
}