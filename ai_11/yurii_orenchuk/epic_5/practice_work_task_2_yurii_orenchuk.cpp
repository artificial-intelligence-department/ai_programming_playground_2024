#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy_file(char *file_from, char *file_to){
    ifstream old_file;
    ofstream new_file;
    old_file.open(file_from, ios::in);
    new_file.open(file_to, ios::out);

    if (old_file.is_open()){
        if (new_file.is_open()){
            
            new_file << old_file.rdbuf();
            if (new_file.fail() || old_file.fail()) {
                cout << "Failed to copy over file elements";
                return Failure;
            }

            old_file.close();
            new_file.close();
            if (new_file.fail() || old_file.fail()) {
                cout << "Failed to close files";
                return Failure;
            }

            return Success;
        } else {
            cout << "Failed to open new file";
            return Failure;
        }
    } else {
        cout << "Failed to open old file";
        return Failure;
    }
}

int main(){
    char file_from[100]; 
    char file_to[100];

    cout << "Enter the file you want to copy: ";
    cin.getline(file_from, 100);

    cout << "Enter the name of the new file: ";
    cin.getline(file_to, 100);

    FileOpResult result = copy_file(file_from, file_to);

    if (result == Success) {
        cout << "Successfully copied file\n";
    }
    else {
        cout << "Failed to copy file\n";
    }
    return 0;
}