#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum FileOpResult
{
    Success,
    Failure,
    OpenError,
    OutputError,
    CloseError
};

FileOpResult write_to_file(char *name, char *content)
{
    fstream file(name, ios::out);
    if (!file.is_open())
        return FileOpResult::OpenError;

    file << content;
    if (file.fail())
        return FileOpResult::OutputError;

    file.close();
    if (file.bad())
        return FileOpResult::CloseError;

    return FileOpResult::Success;
}
FileOpResult copyFile(char *file_from, char *file_to)
{
    fstream file1(file_from, ios::in);
    fstream file2(file_to, ios::out);
    if (!file1.is_open() || !file2.is_open())
        return FileOpResult::OpenError;

    file2 << file1.rdbuf();

    if (file1.fail() || file2.fail())
        return FileOpResult::OutputError;

    file1.close();
    file2.close();
    if (file1.bad() || file2.bad())
        return FileOpResult::CloseError;

    return FileOpResult::Success;
}
std::string interpretCode(FileOpResult resultCode)
{
    switch (resultCode)
    {
    case 0:
        return "Success";
        break;
    case 1:
        return "Failure";
        break;
    case 2:
        return "OpenError";
        break;
    case 3:
        return "OutputError";
        break;
    case 4:
        return "CloseError";
        break;
    default:
        break;
    }
    return "";
}
int main()
{
    string name = "PracticeFile.txt", content;
    cout << "enter content for file: ";
    getline(cin, content);
    FileOpResult resultCode = write_to_file(name.data(), content.data());

    cout << "\nStatus code: " << interpretCode(resultCode) << endl;

    string name1 = "PracticeFile.txt", name2;
    cout << "\nenter name of file to copy: ";
    getline(cin, name2);
    FileOpResult resultCode2 = copyFile(name1.data(), name2.data());

    cout << "\nStatus code: " << interpretCode(resultCode2) << endl;
    return 0;
}
