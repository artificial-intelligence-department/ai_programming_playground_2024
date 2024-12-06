#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

enum FileOpResult {Success, Failure};
FileOpResult write_to_file(char *name, char *content){
    ofstream outFile(name, ios::app);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
    } else {
        return Failure;
    }
    
    outFile.close();

    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to){
    ifstream inFile(file_from, ios::app);
    ofstream outFile(file_to, ios::app);
    
    if (inFile.is_open())
    {   
        if (outFile.is_open())
        {
            string content;
            while (getline(inFile, content)) {
                outFile << content << endl;
            }
        } else {
            cout << "file_to.txt is not found!";
            return Failure;    
        }
    } else {
        cout << "file_from.txt is not found!";
        return Failure;
    }

    inFile.close();
    outFile.close();

    return Success;
}

int main(){
    string file_from = "file_from.txt";
    string file_to = "file_to.txt";
    string content;
    getline(cin, content);
    
    char* file_from_char = new char[file_from.length() + 1];
    strcpy(file_from_char, file_from.c_str());

    char* file_to_char = new char[file_to.length() + 1];
    strcpy(file_to_char, file_to.c_str());

    char* content_char = new char[content.length() + 1];
    strcpy(content_char, content.c_str());

    
    write_to_file(file_from_char, content_char);
    copy_file(file_from_char, file_to_char);

    delete[] file_from_char;
    delete[] file_to_char;
    delete[] content_char;
}

