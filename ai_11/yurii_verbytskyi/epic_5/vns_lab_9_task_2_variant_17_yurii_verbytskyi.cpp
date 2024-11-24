#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int countWords(const string &line) {
    int count = 0, inWord = 0;
    for (char ch : line) {
        if (isspace(ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

void createFileF1(const char *filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        perror("Error creating file F1");
        exit(1);
    }

    cout << "Enter 10 lines of text to write to file F1 (spaces are optional):\n";
    for (int i = 0; i < 10; i++) {
        string line;
        getline(cin, line); 
        file << line << "\n";
    }

    file.close();
}

void copyToFileF2(const char *file1, const char *file2, int N1, int N2) {
    ifstream f1(file1);
    ofstream f2(file2);
    if (!f1.is_open() || !f2.is_open()) {
        perror("Error opening files");
        exit(1);
    }

    string line;
    int currentLine = 0;

    while (getline(f1, line)) {
        currentLine++;
        if ((currentLine >= N1 && currentLine <= N2 && !line.empty() && line[0] == 'A') ||
            currentLine > N2 + 2) {
            f2 << line << "\n";
        }
    }

    f1.close();
    f2.close();
}

void printFile(const char *filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        perror("Error opening file");
        exit(1);
    }

    cout << "The contents of the file " << filename << ":\n";
    string line;
    while (getline(file, line)) {
        cout << line << "\n";
    }
    cout << endl;

    file.close();
}

int getLastLineWordCount(const char *filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        perror("Error opening file");
        exit(1);
    }

    string line, lastLine;
    while (getline(file, line)) {
        lastLine = line; 
    }
    file.close();

    return countWords(lastLine);
}

int main() {
    const char *file1 = "F1.txt";
    const char *file2 = "F2.txt";
    int N1 = 3, N2 = 5; 

    createFileF1(file1);
    printf("\n");
    printFile(file1);
    printf("\n");
    copyToFileF2(file1, file2, N1, N2);

    printFile(file2);
    printf("\n");
    int wordCount = getLastLineWordCount(file2);
    cout << "The number of words in the last line of the file F2: " << wordCount << "\n";

    return 0;
}
