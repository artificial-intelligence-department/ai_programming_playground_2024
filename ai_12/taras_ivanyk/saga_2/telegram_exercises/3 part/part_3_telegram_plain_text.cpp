#include <iostream>
#include <fstream>
using namespace std;

int main(){

// Basic example how to work with file text:

    ofstream write_file("Write_file.txt");
    write_file << "Some text written to this file. \n";
    write_file.close();

    ifstream read_file("Write_file.txt");
    string line;
    cout << "Content of the file: \n";
    while(getline(read_file, line)){
        cout << line << endl;
    }
    read_file.close();

// my interest - how to print emoji on C++, some basic methods:

// 1) using UTF-8 codes:

    cout << "\U0001F600" << endl; 
    cout << "\U0001F604" << endl; 
    cout << "\U0001F609" << endl; 

// 2) For my surprise we can just copy enoji and print it:

    cout << "Smiley face: 😀" << endl;
    cout << "Thumbs up: 👍" << endl;

    return 0;
}