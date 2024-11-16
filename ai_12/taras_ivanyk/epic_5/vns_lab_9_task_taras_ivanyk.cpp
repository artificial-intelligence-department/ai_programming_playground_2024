#include <iostream>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;

bool is_digit(const string& line) {
    for (char ch : line) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

bool start_with_A(const string& line) {
    return !line.empty() && line[0] == 'A';
}

int main() {
    const string filename1 = "F1.txt";
    const string filename2 = "F2.txt";

    ofstream file1(filename1);
    if (!file1) {
        cerr << "Error: file1 не вдалося створити!" << endl;
        return 1;
    }
    file1 << "Apple is a fruit.\n";
    file1 << "123456789\n";
    file1 << "Another line starts with A.\n";
    file1 << "No digits here.\n";
    file1 << "Amazing!\n";
    file1 << "What do you eat for breakfast?.\n";
    file1 << "T0day is a good day!\n";
    file1 << "America amerikano z mlekiem\n";
    file1 << "Bruuuuuuuuuu12uuh\n";
    file1 << "A last se n t e n c e\n";
    file1.close();

    ifstream inputFile(filename1);
    if (!inputFile) {
        cerr << "Error: file1 не вдалося відкрити для читання!" << endl;
        return 1;
    }

    ofstream outputFile(filename2);
    if (!outputFile) {
        cerr << "Error: file2 не вдалося відкрити для запису!" << endl;
        return 1;
    }

    string line;
    int count_A = 0;

    while (getline(inputFile, line)) {
        if (!is_digit(line)) {
            outputFile << line << endl; 
            if (start_with_A(line)) {
                count_A++;
            }
        }
    }
    outputFile << "Number of sentences that start with 'A': " << count_A << endl;

    inputFile.close();
    outputFile.close();

    ifstream readFile(filename2);
    if (!readFile) {
        cerr << "Error: file2 не вдалося відкрити для читання!" << endl;
        return 1;
    }
    cout << "Contents of F2:" << endl;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    readFile.close();

    return 0;
}
