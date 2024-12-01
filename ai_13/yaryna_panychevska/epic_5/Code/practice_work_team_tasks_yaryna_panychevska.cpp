#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum FileOpResult { Success, Failure };
//--------Створення і запис файлу------------//
FileOpResult write_to_file(const string& name, const string& content) {
    if (name == "")
    {
        cout << "Invalid file name!" << endl;
        return Failure;
    }

    ofstream MyFile(name);
    if (!MyFile.is_open())
    {
        cout << "Uh oh, seems file " << name << " could not be open :(" << endl;
        return Failure;
    }

    MyFile << content;
    if (MyFile.fail()) {
        cout << "Some problems with data for this file. " << endl;
        return Failure;
    }

    MyFile.close();
    if (MyFile.fail()) {
        cout << "Can't close the " << name << " file" << endl;
        return Failure;
    }
    return Success;
}
//--------Копіювання вмісту файлу1 до фалу2------------//
FileOpResult copy_file(const string& file_from, const string& file_to) {
    if (file_from.empty() || file_to.empty()) {
        cout << "File names cannot be empty!" << endl;
        return Failure;
    }

    ifstream MySourceFile(file_from, ios::in);
    if (!MySourceFile.is_open()) {
        cout << "Uh oh, seems that open source file " << file_from << " file can't be opened :(" << endl;
        return Failure;
    }

    ofstream MyDestFile(file_to, ios::out | ios::trunc);
    if (!MyDestFile.is_open()) {
        cout << "Uh oh, seems that destination file " << file_to << " could not be created opened :(" << endl;
        MySourceFile.close();
        return Failure;
    }

    string line;
    while (getline(MySourceFile, line)) {
        MyDestFile << line << "\n";
        if (MyDestFile.fail()) {
            cout << "Oops! Failed to write data to " << file_to << " file!" << endl;
            MySourceFile.close();
            MyDestFile.close();
            return Failure;
        }
    }

    if (MySourceFile.bad()) {
        cout << "Oops! Failed to read data from " << file_from << " file!" << endl;
        MySourceFile.close();
        MyDestFile.close();
        return Failure;
    }

    MySourceFile.close();
    MyDestFile.close();

    return Success;
}

int main() {
    //--------Пункт 1----------------------------------------//
    string fileName, content;
    cout << "Enter file name: ";
    getline(cin, fileName);

    cout << "Enter data you want to write to " << fileName << " file: ";
    getline(cin, content);
    FileOpResult write_result = write_to_file(fileName, content);

    if (write_result == Success) {
        cout << "File was written successfully!" << endl;
    }
    else {
        cout << "Failed to write to the file :( " << endl;
    }
//--------Пункт 2----------------------------------------//
    string copyfileName;
    cout << "Enter the destination file name for copying: ";
    getline(cin, copyfileName);

    FileOpResult copy_result = copy_file(fileName, copyfileName);
    if (copy_result == Success) {
        cout << "File was copied successfully!" << endl;
    }
    else {
        cout << "Failed to copy the file :(" << endl;
    }
    return 0;
}