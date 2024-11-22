#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

enum FileOpResult1 { Failure1, Success1 };

FileOpResult1 const write_to_file(const char *name,const char *content){
    fstream file(name, fstream::out);
    if(!file) return Failure1;
    file.write(content, strlen(content));
    file.close();
    return Success1;
}

enum FileOpResult2 { Success2, Failure2};

FileOpResult2 const copy_file(const char *file_from, const char *file_to){
    fstream file1(file_from, fstream::in);
    if(!file1) return Failure2;
    fstream file2(file_to, fstream::out);
    if(!file2) return Failure2;
    string line;
    while(getline(file1, line)){
        line += "\n";
        file2.write(line.c_str(), line.size());
    }
    file1.close();
    file2.close();
    return Success2;
}
int main(){
    string name, content;
    cout << "Enter file name : ";
    getline(cin, name);
    name += ".txt";
    cout << "Enter file content: ";
    getline(cin, content);

    FileOpResult1 result1 = write_to_file(name.c_str(), content.c_str());
    if(result1 == Success1) cout << " success\n";
    else cout << "Failure";

    string file1, file2;
    cout << "Enter name of file to copy from: ";
    getline(cin, file1);
    cout << "Enter name of file in which to copy: ";
    getline(cin, file2);
    file1 += ".txt";
    file2 += ".txt";
    FileOpResult2 result2 = copy_file(file1.c_str(), file2.c_str());
    if(result2 == Success2) cout << "success\n";
    else cout << "Failure";
    
    return 0;
}