#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 

using namespace std;

bool is_consonant(char c) {
    c = tolower(c); 
    return (c >= 'a' && c <= 'z') && (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y');
}

int count_consonants(const string &line) {
    int count = 0;
    for (char c : line) {
        if (is_consonant(c)) {
            count++;
        }
    }
    return count;
}

int main() {

    ofstream file_F1("F1.txt");
    if (!file_F1) {
        cout << "Error: Cannot create file F1.txt\n";
        return 1;
    }

    file_F1 << "All clouds have souls.\n";
    file_F1 << "We just sat there and said nothing.\n";
    file_F1 << "I hope this turns into something great.\n";
    file_F1 << "We chose a table near the fountain and talked all evening.\n";
    file_F1 << "It’s late at night and everyone is asleep.\n";
    file_F1 << "The feelings of strangeness are deeper and stronger today.\n";
    file_F1 << "I often wonder why artists marry so much.\n";
    file_F1 << "The sun is really angry this afternoon.\n";
    file_F1 << "Nothing is stranger than a good day.\n";
    file_F1 << "It felt wrong to read.\n";

    file_F1.close();

    int N, K;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter K: ";
    cin >> K;

    if (N < 1 || K < N || K > 10) {
        cout << "Invalid range of lines.\n";
        return 1;
    }

    ifstream file_F1_read("F1.txt");
    ofstream file_F2("F2.txt");

    if (!file_F1_read || !file_F2) {
        cout << "Error: Cannot open files.\n";
        return 1;
    }

    string line;
    int current_line = 1;

    while (getline(file_F1_read, line)) {
        if (current_line >= N && current_line <= K) {
            file_F2 << line << "\n";  
        }
        current_line++;
    }

    file_F1_read.close();
    file_F2.close();

    ifstream file_F2_read("F2.txt");

    if (!file_F2_read) {
        cout << "Error: Cannot open file F2.txt for reading.\n";
        return 1;
    }

    int consonant_сount = 0;
    while (getline(file_F2_read, line)) {
        consonant_сount += count_consonants(line); 
    }

    file_F2_read.close();

    cout << "The amount of consonant letters in file F2: " << consonant_сount << endl;

    return 0;
    }
