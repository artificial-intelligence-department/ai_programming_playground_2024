#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int OddNumbers(int n, int mas[]) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (mas[i] % 2 != 0) {
            result++;
        }
    }
    return result;
}

int Words(const string& line) {
    int result = 0;
    bool word = false;
    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];
        if (isspace(ch)) {
            word = false;
        } else if (!word) {
            word = true;
            result++;
        }
    }
    return result;
}

int main() {
    cout << "a)" << endl;
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    cout << "Odd numbers: " << OddNumbers(n, mas) << endl;

    cin.ignore();

    cout << "b)" << endl;
    string line;
    getline(cin, line);
    cout << "Number of words: " << Words(line) << endl;

    return 0;
}
