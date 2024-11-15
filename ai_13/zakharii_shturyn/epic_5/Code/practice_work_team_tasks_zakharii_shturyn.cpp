#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

enum FileOpResult{Failure, Success};
FileOpResult write_to_file(char* name, char* content) {
    if(strlen(name) == 0) {
        cout << "Cannot create file without name" << endl;
        return Failure;
    }
    ofstream myFile(name);
    if (myFile.is_open()) {
        myFile << content << endl;
        if(myFile.fail()) {
            cout << "Error while writing data";
            return Failure;
        }

        myFile.close();
        if(myFile.fail()) {
            cout << "Error closing file";
            return Failure;
        }
    } else {
        cout << "Can't open file" << endl;
        return Failure;
    }
    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to) {
    if(strlen(file_from) == 0 || strlen(file_to) == 0) {
        cout << "Cannot create file without name" << endl;
        return Failure;
    }
    FILE* myFile = fopen(file_from, "r");
    if (myFile != NULL) {
        char line[100];
        while(fgets(line, sizeof(line), myFile)){
                line[strcspn(line, "\n")] = 0;
                if(!write_to_file(file_to, line)) {
                    return Failure;
                }
            }

        fclose(myFile);
    } else {
        cout << "Not such file" << endl;
        return Failure;
    }
    return Success;
}


int main() {
    char filename1[20];
    char content[100];
    printf("Enter name of file: \n");
    gets(filename1);
    printf("Enter content for file: \n");
    gets(content);
    if(write_to_file(filename1, content)) {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
        return 0;
    }

    char filename2[20];
    printf("Enter name of file to copy: \n");
    gets(filename2);
    if(copy_file(filename1, filename2)) {
        cout << "Success" << endl;
    } else {
        cout << "Failure" << endl;
        return 0;
    }

    return 0;
}