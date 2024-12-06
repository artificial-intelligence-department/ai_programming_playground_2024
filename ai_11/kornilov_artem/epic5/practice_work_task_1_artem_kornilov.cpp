#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>

using namespace std;

const int MAXLINE = 512;

void write_to_file(char* name, char* content) {
    ofstream file1(name, ios::binary);
    if (!file1) {
        cerr << "Error: File1 could not be opened." << endl;
        exit(1);
    }
    
    file1.write(content, strlen(content));
    file1.close();

    cout << "Contet inputed in File1 seccessfully!" << endl;
}

void copy_file_to_file(char* name) {
    ifstream file1 (name, ios::binary);
    if (!file1) {
        cerr << "Error: File1 could not be opened." << endl;
    }

    ofstream file2 ("File2.txt", ios::binary);
    if (!file2) {
        cerr << "Error: File2 could not be opened." << endl;
    }

    char temp[MAXLINE];

    // file2 << inFile.rdbuf();
    while (file1.read(reinterpret_cast<char*>(temp), strlen(temp)) || file1.gcount() > 0) {
        file2.write(temp, file1.gcount());
    }

    file1.close();
    file2.close();

    cout << "File copied succesfully!" << endl;
}

void display_file(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Could not open file " << filename << " for reading." << endl;
        return;
    }

    cout << "Contents of " << filename << ":" << endl;
    char temp[MAXLINE];
    while (file.read(temp, sizeof(temp)) || file.gcount() > 0) {
        cout.write(temp, file.gcount());
    }
    cout << endl;

    file.close();
}

int main () {
    
    char name[] = "File1.txt";
    char content[MAXLINE];

    cin.getline(content, MAXLINE);

    write_to_file(name, content);

    copy_file_to_file(name);

    display_file(name);
    display_file("File2.txt");
    
    return 0;
}