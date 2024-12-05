#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

void file_F1(const string& filename) {
    ofstream file(filename);
    cout << "Enter content for F1:\n";
    string line;
    while (true) {
        getline(cin, line);
        if (line.empty()) break;
        file << line << "\n";
    }
    file.close();
}

vector<string> read(const string& filename) {
    ifstream file(filename);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();
    return lines;
}
void write(const string& filename, const vector<string>& lines) {
    ofstream file(filename);
    for (const auto& line : lines) {
        file << line << "\n";
    }
    file.close();
}
vector<string> filter(const vector<string>& lines, int N1, int N2) {
    vector<string> filtered_lines;
    for (int i = N1 - 1; i < N2; ++i) {
        if (!lines[i].empty() && lines[i][0] == 'А') {
            filtered_lines.push_back(lines[i]);
        }
    }
    for (int i = N2 + 2; i < lines.size(); ++i) {
        filtered_lines.push_back(lines[i]);
    }
    return filtered_lines;
}
int count(const string& line) {
    int wordCount = 0;
    bool inWord = false;
    for (char c : line) {
        if (isspace(c)) {
            if (inWord) {
                ++wordCount;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }
    if (inWord) {
        ++wordCount;
    }
    return wordCount;
}
int main() {
    const string F1 = "F1.txt";
    const string F2 = "F2.txt";

    file_F1(F1);
    int N1, N2;
    cout << "Введіть N1 та N2: ";
    cin >> N1 >> N2;
    cin.ignore(); 
    vector<string> linesF1 = read(F1);
    vector<string> linesF2 = filter(linesF1, N1, N2);
    write(F2, linesF2);

    if (!linesF2.empty()) {
        const string& lastLine = linesF2.back();
        int wordCount = count(lastLine);
        cout << "Кількість слів в останньому рядку F2: " << wordCount << endl;
    } else {
        cout << "Файл F2 порожній." << endl;
    }
    return 0;
}
