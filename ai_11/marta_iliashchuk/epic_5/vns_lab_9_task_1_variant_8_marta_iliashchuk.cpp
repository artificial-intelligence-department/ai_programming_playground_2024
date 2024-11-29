#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    string result;
    string input;
    vector<string> lines;
    string A = "A";
    int count = 0;

    FILE* first = fopen("F1.txt", "w");
    FILE* second = fopen("F2.txt", "w");

    if (first == nullptr || second == nullptr) {
        cerr << "Error opening file" << endl;
        exit(1);
    }

    cout << "Enter 10 strings:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ") ";
        getline(cin, input);

        fputs(input.c_str(), first);
        fputs("\n", first);

        string noDigits;
        for (char wordInLine : input) {
            if (!isdigit(wordInLine)) {
                noDigits += wordInLine;
            }
        }

        lines.push_back(noDigits);
    }

    fclose(first);

    for (const string& line : lines) {
        fputs(line.c_str(), second);
        fputs("\n", second);
    }

    fclose(second);

    for (string line : lines){
        if(line[0] == A[0]){
            count++;
        }
    }

    cout << "Done" << endl;
    cout<<count;
    return 0;
}