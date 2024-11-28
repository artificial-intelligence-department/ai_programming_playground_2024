#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

enum FileOpResult
{
    Success,
    Failure,
    OpeningError,
    WritingError
};

FileOpResult write_to_file(char *name, char *content)
{
    ofstream file(name);
    if (!file) return Failure;
    
    file << content << endl;
    if (file.fail()) return WritingError;
    
    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to)
{
    ifstream file1(file_from);
    ofstream file2(file_to);

    if (!file1.is_open()) return OpeningError;
    
    if (!file2) return Failure;

    string line;
    while (getline(file1, line))
    {
        file2 << line << endl;
        if (file2.fail()) return WritingError;
    }

    return Success;
}

void results(FileOpResult r){
    switch (r)
    {
    case 0:
        cout << "Succes" <<endl;
        break;
    case 1:
        cout << "Error crearing file" << endl;
        break;
    case 2:
        cout << "Error opening file" << endl;
        break;
    case 3:
        cout << "Error writing in file"<<endl;
        break;
    default:
        break;
    }
}

int main()
{
    char fname[255];
    char str[255];
    cout << "Enter name of the file: ";
    cin.getline(fname, 255);
    cout << "Enter line: ";
    cin.getline(str, 255);

    FileOpResult write_result = write_to_file(fname, str);
    results(write_result);

    char fname1[255];
    cout << "Enter name of the first file: ";
    cin.getline(fname1, 255);
    char fname2[255];
    cout << "Enter name of the second file: ";
    cin.getline(fname2, 255);

    FileOpResult copy_result = copy_file(fname1, fname2);
    results(copy_result);

    return 0;
}