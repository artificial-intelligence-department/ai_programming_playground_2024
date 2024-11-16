#include <iostream>
#include <fstream>
#include <string>
using namespace std;
enum FileOpResult
{
    Success,
    Failure
};
FileOpResult copy_file(char *file1, char *file2);
int main()
{
    const int SIZE = 5;
    int value = 5;
    string name = "Hello, my name is Roman!";
    double arr[SIZE] = {4.45, 12.43534, -4.3453, 1.01, 90.329};
    char file1Name[] = "File1";
    char file2Name[] = "CopyFile1";
    ofstream fileStream(file1Name);
    if (!fileStream.is_open())
    {
        return Failure;
    }
    fileStream << value << "\n"
               << name << "\n";
    for (int i = 0; i < SIZE; i++)
    {
        fileStream << arr[i] << " ";
    }
    fileStream.close();
    FileOpResult res = copy_file(file1Name, file2Name);
    if (res == Success)
    {
        cout << "Success!" << endl;
    }
    else
    {
        cout << "Failure!" << endl;
    }
}

FileOpResult copy_file(char *file1, char *file2)
{
    string line;
    ifstream firstFile(file1);
    ofstream destFile(file2);
    if (!firstFile.is_open() || !destFile.is_open())
    {
        return Failure;
    }
    destFile << firstFile.rdbuf();
    if (!firstFile.good() || !destFile.good())
    {
        return Failure;
    }
    firstFile.close();
    destFile.close();
    return Success;
}