#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult{Success, Failure};
FileOpResult write_to_file(const string& content)
{

ofstream outfile("nameFile.txt");
if(!outfile.is_open())
{
    cout << "Error: Unable to creat the file";
    return FileOpResult::Failure;
}

outfile << content;
outfile.close();

ifstream infile("nameFile.txt");
if(!infile.is_open())
{
    cout << "Error: Unable to read the file";
    return FileOpResult::Failure;
}

char c;
while(infile.get(c))
{
    cout << c;
}

return FileOpResult::Success;
}

FileOpResult copy_file(const string& sourcePath, const string& destinationPath)
{

ifstream sourceFile(sourcePath);
if(!sourceFile.is_open())
{
    cout << "Error: Unable to open a file";
    return FileOpResult::Failure;
}

ofstream destinationFile(destinationPath);
if(!destinationFile.is_open())
{
    cout << "Error: Unable to creat a file";
    return FileOpResult::Failure;
}

string readLine;
while(getline(sourceFile, readLine))
{
    destinationFile << readLine << '\n';

}

destinationFile.close();

ifstream readfile(destinationPath); 
if(!readfile.is_open())
{
    cout << "Error: Unable to craeat a file";
    return FileOpResult::Failure;
}

char ch;
while(readfile.get(ch))
{
    cout << ch;
}

cout << "Content of the file " << destinationPath << ":\n";

readfile.close();
sourceFile.close();

cout << "Content copied from " << sourcePath << " to " << destinationPath << "\n";
return FileOpResult::Success;

}


int main()
{
    string content;
    cout << "Enter content to write to the file: ";
    getline(cin, content);

    FileOpResult result = write_to_file(content);
    if (result == FileOpResult::Success) 
    {
        cout << "\nFile operation completed successfully.\n";
    } else 
    {
        cout << "\nFile operation failed.\n";
    }

    FileOpResult copyResult = copy_file("nameFile.txt", "fileCopy.txt");
    if (copyResult == FileOpResult::Success) 
    {
    std::cout << "File copied successfully.\n";
    } else 
    {
    std::cerr << "File copy failed.\n";
    }

    return 0;

}
