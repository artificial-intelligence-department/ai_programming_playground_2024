#include <iostream>
#include <fstream>
using namespace std;

enum FileOpResult {Success, FailureCreate, FailureOpen, FailureWrite};

FileOpResult write_to_file(char *name, char *content){

    if (name == nullptr){
        return FailureCreate;
    }

    ofstream file(name);
    if (!file.is_open()) {
        return FailureOpen;
    }

    file<<content;

    if(file.fail()){
        return FailureWrite;
    }

    file.close();
    return Success;
}

int main(){
    char fileName[124];
    char content[777];

    cout<<"Enter filename: ";
    cin.getline(fileName, 100);

    cout<<"Enter content: ";
    cin.getline(content, 1000);

    FileOpResult result = write_to_file(fileName, content);

    if (result == Success) {
        cout << "Data successfully written to the file";
    } 
    else if (result == FailureCreate) {
        cout << "Failed to create the file: missing filename";
    } 
    else if (result == FailureOpen) {
        cout << "Error opening the file";
    } 
    else if (result == FailureWrite) {
        cout << "Error writing data to the file";
    }

    return 0;
}
