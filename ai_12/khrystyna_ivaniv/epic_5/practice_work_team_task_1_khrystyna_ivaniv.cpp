#include <iostream>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char *name, const char *content)
{
    if (name == nullptr || content == nullptr)
    {
        cout << "Error: Null file name or content.\n";
        return Failure;
    }

    ofstream file(name);
    if (!file.is_open())
    {
        cout << "Error: Cannot open file \"" << name << "\" for writing.\n";
        return Failure;
    }

        file << content;

    file.close();
    if (file.fail())
    {
        cout << "Error: File closing failed.\n";
        return Failure;
    }
    return Success;
}

int main()
{
    char file_name_write[256];
    char content[1024];

    cout << "Enter file name: ";
    cin.getline(file_name_write, 256);

    cout << "Enter content to write: ";
    cin.getline(content, 1024);

    FileOpResult result = write_to_file(file_name_write, content);
    if (result == Success)
    {
        cout << "File written successfully.\n";
    }
    else
    {
        cout << "Failed to write to file.\n";
    }

    return 0;
}