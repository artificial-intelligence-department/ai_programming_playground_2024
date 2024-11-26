#include <iostream>
#include <fstream>
#include <string>

using namespace std;


enum FileOpResult { 
    Success, 
    Failure 
};


FileOpResult write_to_file(const string& name, const string& content);
FileOpResult copy_file(const char* file_from, const char* file_to);


int main() {
    string choice;

    cout << "Available operations:\n"; 
    cout << "1. Create or overwrite a file: \n";
    cout << "2. Copy the contents of one file to another\n";
    cout << "What do you want to do?: ";
    cin >> choice;
    cin.ignore();

    if (choice == "1") {
        string file_name, content;

        cout << "Enter file name: ";
        getline(cin, file_name);

        cout << "Enter content to write: ";
        getline(cin, content);

        FileOpResult result = write_to_file(file_name, content);

        if (result == Success)  cout << "File written successfully";
        else cout << "Failed to write file";
        
    } else if (choice == "2") {
        char source_file[256];
        char target_file[256];

        cout << "Enter source file name: ";
        cin.getline(source_file, sizeof(source_file));

        cout << "Enter target file name: ";
        cin.getline(target_file, sizeof(target_file));

        FileOpResult result = copy_file(source_file, target_file);

        if (result == Success) {
            cout << "File copied successfully";
        } else {
            cout << "Failed to copy file";
        }

        } else cout << "Wrong input";

    return 0;
}


FileOpResult write_to_file(const string &name, const string &content) {
    if (name.empty()) {
        cerr << "Error: File name is empty." << endl;
        return Failure;
    }

    try {
        ofstream file(name, ios::binary);

        if (!file.is_open()) {
            cerr << "Error: Unable to open file '" << name << "'." << endl;
            return Failure;
        }

        file << content;

        if (file.fail()) {
            cerr << "Error: Failed to write to file '" << name << "'." << endl;
            return Failure;
        }

        file.close();
        return Success;
    } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
        return Failure;
    }
}


FileOpResult copy_file(const char *file_from, const char *file_to) {
    bool fileExist;

    ifstream fileChekOne(file_from);
    fileExist = fileChekOne.is_open();
    fileChekOne.close();
    if (!fileExist) {
        cout << "Sourse file doesn't exist\n";
        return Failure;
    }

    ifstream fileChekTwo(file_to);
    fileExist = fileChekTwo.is_open();
    fileChekTwo.close();
    if (!fileExist) {
        cout << "Target file doesn't exist\n";
        return Failure;
    }

    try {
        ifstream input_file(file_from, ios::binary);
        ofstream output_file(file_to, ios::binary);
 
        const size_t buffer_size = 4096;
        char buffer[buffer_size];
        while (input_file.read(buffer, buffer_size)) {
            output_file.write(buffer, input_file.gcount());
        }

        if (input_file.eof()) {
            output_file.write(buffer, input_file.gcount());
        } else {
            cerr << "Error: Failed during file read/write operations\n";
            return Failure;
        }

        if (output_file.fail()) {
            cerr << "Error: Failed to write to target file\n";
            return Failure;
        }

        return Success;

    } catch (const exception &e) {
        cerr << "Exception: " << e.what() << endl;
        return Failure;
    }
}




    
