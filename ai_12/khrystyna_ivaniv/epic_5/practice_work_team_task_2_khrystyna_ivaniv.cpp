#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure};

FileOpResult copy_file(const char *file_from,const char *file_to){
    ifstream file1(file_from, ifstream::in);
    if(!file1) 
    return Failure;
    fstream file2(file_to, fstream::out);
    if(!file2)
    return Failure;
    string line;
    while(getline(file1, line)){
        line += "\n";
        file2.write(line.c_str(), line.size());
    }
    file1.close();
    file2.close();
    return Success;
}

int main(){
    string file1, file2;
    cout << "Enter name of the first file: ";
    getline(cin, file1);
    cout << "Enter name of the second file: ";
    getline(cin, file2);
    file1 += ".txt";
    file2 += ".txt";
    FileOpResult result = copy_file(file1.c_str(), file2.c_str());
    if(result == Success) 
    cout << "Content was successfully copied!";
    else
    cout << "Failed to copy files(";
    return 0;
}
