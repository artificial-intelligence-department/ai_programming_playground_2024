#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool has_duplicate_words(const string &line) {
    istringstream iss(line);
    vector<string> words;
    string word;

    while (iss >> word) {
        if (find(words.begin(), words.end(), word) != words.end()) {
            return true; 
        }
        words.push_back(word);
    }
    return false;
}

void copy_lines_with_duplicates(ifstream &F1, ofstream &F2) {
    string line;
    while (getline(F1, line)) {
        if (has_duplicate_words(line)) {
            F2 << line << endl;
        }
    }
}

void find_word_with_max_a(ifstream &F1) {
    F1.clear();           
    F1.seekg(0);          
    string line;
    int line_number = 1;

    while (getline(F1, line)) {
        istringstream iss(line);
        string word;
        int max_a_count = 0, max_word_index = -1, word_index = 0;

        while (iss >> word) {
            int a_count = count_if(word.begin(), word.end(), [](char ch) {
                return tolower(ch) == 'a';
            });

            if (a_count > max_a_count) {
                max_a_count = a_count;
                max_word_index = word_index + 1;
            }
            ++word_index;
        }

        if (max_word_index > 0) {
            cout << "Line " << line_number << ": word #" << max_word_index
                 << " has the most 'A' (" << max_a_count << ")." << endl;
        }
        ++line_number;
    }
}

int main() {
    string file1 = "F1.txt";
    string file2 = "F2.txt";

    ofstream F1(file1);
    if (!F1.is_open()) {
        cerr << "Error creating file F1" << endl;
        return 1;
    }

    cout << "Enter at least 10 lines for file F1:" << endl;
    string line;
    for (int i = 0; i < 10; ++i) {
        getline(cin, line);
        F1 << line << endl;
    }
    F1.close();

    ifstream F1_read(file1);
    ofstream F2(file2);
    if (!F1_read.is_open() || !F2.is_open()) {
        cerr << "Error opening files" << endl;
        return 1;
    }

    copy_lines_with_duplicates(F1_read, F2);


    F1_read.clear(); 
    F1_read.seekg(0); 
    find_word_with_max_a(F1_read);

    F1_read.close();
    F2.close();

    cout << "Tasks completed. Check F2.txt for results." << endl;

    return 0;
}
