#include <iostream>
#include <string>
using namespace std;

int u_letter_count(const string& s) {
    char uniqueLetters[26];
    int count = 0;

    for (char letter : s) {
        bool isUnique = true;

        for (int i = 0; i < count; i++) {
            if (uniqueLetters[i] == letter) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            uniqueLetters[count] = letter;
            count++;
        }
    }

    return count;
}

int main() {
    string s;
    cin >> s;

    cout << u_letter_count(s);

    return 0;
}
