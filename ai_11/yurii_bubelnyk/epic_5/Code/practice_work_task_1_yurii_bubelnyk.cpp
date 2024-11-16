#include <iostream>
#include <cstdio>
using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const char* name, const char* content) {
    FILE* file = fopen(name, "w");
    
    if (file == nullptr) {
        return Failure;
    }

    if (fputs(content, file) == EOF) {
        fclose(file);
        return Failure;
    }

    fclose(file); 
    return Success; 
}
FileOpResult copy_file(const char* file_from, const char* file_to) {
   
    FILE* file1 = fopen(file_from, "r");
    if (file1 == nullptr) {
        return Failure; 
    }

    FILE* file2 = fopen(file_to, "w");
    if (file2 == nullptr) {
        fclose(file1); 
        return Failure;
    }

    char content[256];

    while (fgets(content, sizeof(content), file1) != nullptr) {
        if (fputs(content, file2) == EOF) {
            fclose(file1);
            fclose(file2);
            return Failure;
        }
    }

    fclose(file1);
    fclose(file2);
    return Success;
}
int main() {
    const char* filename1 = "file_from.txt";
    const char* filename2 = "file_to.txt";

    char content[256]; 

    cout << "Enter content to write to the file: ";
    cin.getline(content, sizeof(content));

    FileOpResult result = write_to_file(filename1, content);
    if (result == Success) {
        cout << "File successfully written to " << filename1 << endl;
    } else {
        cout << "Failed to write to " << filename1 << endl;
    }

    result = copy_file(filename1, filename2);
    if (result == Success) {
        cout << "File successfully copied to " << filename2 << endl;
    } else {
        cout << "Failed to copy file to " << filename2 << endl;
    }

    return 0;
}
