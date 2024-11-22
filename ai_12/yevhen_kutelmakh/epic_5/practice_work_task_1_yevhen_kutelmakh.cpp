#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

enum FileOpResult {
    Failure,
    Success,
};

FileOpResult write_to_file(char *name, char *content, bool n = false) {
    ofstream file; 
    if (n) file.open(name, ios::app); 
    else file.open(name); 
    if(file.is_open()) {
        file << content << "\n";
        file.close();
        ifstream file(name);
        if(file.is_open()) {
            char s[100];
            bool found = false;
            while(file.getline(s, sizeof(s))) {
                if(strcmp(s, content)==0) {
                    found = true;
                    break;
                }
            }
            if(found) return Success;
            cerr << "Error: file`s text doesn`t match ours\n";
            return Failure;
        } else {
            cerr << "Error: file couldn`t get opened for reading";
            return Failure;
        }
    } else {
        cerr << "Error: file couldn`t get opened for writing";
        return Failure;
    } 
}

FileOpResult copy_file(char *file_from, char *file_to) {
    ifstream file1(file_from);
    ofstream f(file_to);
    f.close();
    fstream file2(file_to);
    if(file1.is_open()&&file2.is_open()) {
        string str;
        while(getline(file1, str))
            file2 << str << "\n";
        file2.close(); file1.close();
        file2.open(file_to, ios::in);
        file2.open(file_to, ios::in);
        if(file2.is_open()) {
            file2.seekg(0, ios::beg);
            file1.seekg(0, ios::beg);
            string s1, s2;
            while(getline(file1, s1) || getline(file2, s2)) {
                if(s1!=s2) {
                    cerr << "Data of files isn`t the same";
                    return Failure;
                }
                s1 = " ";
                s2 = "";
            }
            return Success;
        }
        else {
            cerr << "Couldn`t open file2 again";
            return Failure;
        }
    } else {
        cerr << "Couldn`t open one of files";
        return Failure;
    }
}

int main() {
    cout << "Hello, what do you want to do today?\nBut firstly you have to create a file\n";
    char filename[100];
    cout << "Enter a filename: ";
    cin.getline(filename, 99);
    char str[100];
    cout << "Enter text you want to write into your file: ";
    cin.getline(str, 99);
    if(write_to_file(filename, str)) {
        cout << "Writing file went smoosely\n";
    } else exit(1);
    cout << "Now you can either add new string into your file or new file, or copy-paste from one file to another\n";
    char c;
    while(true) {
        cout << "Enter m for creating new file, a for adding new strings, c for copying, e for exit: ";
        cin >> c;  
        cin.ignore();
        switch(c) {
            case 'e':
                return 0;
            case 'm':{
                char filename[100];
                cout << "Enter a filename: ";
                cin.getline(filename, 99);
                char str[100];
                cout << "Enter text you want to write into your file: ";
                cin.getline(str, 99);
                if(write_to_file(filename, str)) {
                    cout << "Writing file went smoosely\n";
                } else exit(0);
            } break;
            case 'a':{
                char filename[100];
                cout << "Enter a filename: ";
                cin.getline(filename, 99);
                char str[100];
                cout << "Enter text you want to write into your file: ";
                cin.getline(str, 99);
                if(write_to_file(filename, str, true)) {
                    cout << "Writing file went smoosely\n";
                } else exit(1);
            } break;
            case 'c':{
                char copyF[100];
                char copyT[100];
                cout << "What file do you want to copy data from? ";
                cin >> copyF;
                cout << "What file do you want to copy data into? ";
                cin >> copyT;
                if(copy_file(copyF, copyT)) {
                    cout << "Copying went smoosely\n";
                } else exit(2);
            } break;
            default: 
                cout << "Incorrect input, try again:\n"; break;
        }  
    }
}