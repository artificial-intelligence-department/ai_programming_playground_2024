#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(const string& filename, const string& content);
FileOpResult copy_file(const string& file_from, const string& file_to);

int main() {
    string filename1 = "file1.txt";
    string filename2 = "file2.txt";
    string content;

    cout << "Enter content to write to file: ";
    getline(cin, content);

    if (write_to_file(filename1, content) == Success) {
        cout << "Success. File created." << endl;
    } else {
        cout << "Failure. File could not be created." << endl;
    }

    if (copy_file(filename1, filename2) == Success) {
        cout << "Success. File is copied." << endl;
    } else {
        cout << "Failure copying file." << endl;
    }

    return 0;
}

FileOpResult write_to_file(const string& filename, const string& content) {
    if (filename.empty()) {
        return Failure;
    }

    ofstream file(filename, ios::out | ios::trunc);
    if (!file) {
        return Failure;
    }

    file << content;

    if (!file) {
        return Failure;
    }

    return Success;
}

FileOpResult copy_file(const string& file_from, const string& file_to) {
    if (file_from.empty() || file_to.empty()) {
        return Failure;
    }

    ifstream in_file(file_from);
    ofstream out_file(file_to);

    if (!in_file || !out_file) {
        return Failure;
    }

    string line;
    while (getline(in_file, line)) {
        out_file << line << '\n';
        if (!out_file) {
            return Failure;
        }
    }

    return Success;
}
