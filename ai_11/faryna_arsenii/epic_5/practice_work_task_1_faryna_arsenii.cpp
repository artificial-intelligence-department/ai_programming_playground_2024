#include <iostream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(char* name, char* content){
    
    if (name == NULL || content == NULL){
        cout << "Error, because null file provided." << endl;
        return Failure;
    }

    FILE* file = fopen(name, "w");
    if (file == NULL){
        cout << "Error while writing to file." << endl;
        return Failure;
    }

    if (fputs(content, file) == EOF){
        cout << "Error while writing to file." << endl;
        fclose(file);
        return Failure;
    }

    if (fclose(file) != 0){
        cout << "Error while closing the file." << endl;
        return Failure;
    }

    return Success;
}

int main (){

    char filename[255];
    char content[1000];

    cout << "Enter the filename" << endl;
    cin.getline(filename, 255);

    cout << "Enter the content of file: " << endl;
    cin.getline(content, 1000);

    FileOpResult result = write_to_file(filename, content);

    if (result == Success){
        cout << "File has been written successfully." << endl;
    }
    else{
        cout << "Error while writing the file." << endl;
    }

    return 0;
}