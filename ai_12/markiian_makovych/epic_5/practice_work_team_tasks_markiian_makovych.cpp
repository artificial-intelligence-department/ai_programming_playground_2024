#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum FileOpResult
{
    Success,
    Failure
};

FileOpResult write_to_file(string name, string content)
{

    if (name.empty() || content.empty())
    {
        return Failure;
    }

    ofstream file(name, ios::out | ios::trunc);

    if (!file.is_open())
    {
        return Failure;
    }

    file << content;

    if (!file.is_open())
    {
        file.close();
        return Failure;
    }
    file.close();
    return Success;
}

FileOpResult copy_file(string fileFrom, string fileTo)
{
    if (fileFrom.empty() || fileTo.empty())
    {
        return Failure;
    }
    ifstream src(fileFrom);
    if (!src.is_open())
    {
        return Failure;
    }

    ofstream destination(fileTo, ios::out | ios::trunc);
    if (!destination.is_open())
    {
        src.close();
        return Failure;
    }

    destination << src.rdbuf();

    if (!destination)
    {
        src.close();
        destination.close();
        return Failure;
    }

    src.close();
    destination.close();

    if (!src || !destination)
    {
        return Failure;
    }

    return Success;
}

int main()
{
    string content, name, fileFrom, fileTo;
    cout << "File name:" << endl;
    getline(cin, name);
    cout << "What do you want to write?" << endl;
    getline(cin, content);

    FileOpResult result = write_to_file(name, content);

    if (result == Success)
    {
        cout << "Everything is correct" << endl;
    }
    else
    {

        cout << "Something went wrong" << endl;
    }
    cout << endl;
    cout << "From which file you want to copy?" << endl;
    getline(cin, fileFrom);
    cout << "In which file you want to write?" << endl;
    getline(cin, fileTo);
    FileOpResult result1 = copy_file(fileFrom, fileTo);
    if (result1 == Success)
    {
        cout << "Everything is correct" << endl;
    }
    else
    {

        cout << "Something went wrong" << endl;
    }

    return 0;
}