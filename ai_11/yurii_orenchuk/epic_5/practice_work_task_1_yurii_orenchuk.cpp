#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(char *name, char *content){
    fstream file;
    file.open(name, ios::out);

    if (file.is_open()) {
        file << content;

        if (file.fail()){
        cout << "Error while writing content into file.\n";
        file.close();
        return Failure;
        }

        file.close();

        if (file.fail()){
        cout << "Error while closing file.\n";
        file.close();
        return Failure;
        }

        return Success;
    } else {
        cout << "Error opening file.\n";
        return Failure;
        }
}

int main(){
    char name[200]; 
    char content[500];

    cout << "Enter the file name: ";
    cin.getline(name, 1000);

    cout << "Enter what you want to write into the file: ";
    cin.getline(content, 1000);

    FileOpResult res = write_to_file(name, content);

    if (res == Success){
        cout << "Operation is successfull!";
    } else cout << "Operation Failed...";

    return 0;
}