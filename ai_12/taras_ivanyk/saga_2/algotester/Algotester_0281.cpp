// ***********************************
//             Algotester 0281
//               Поле Чудес
#include <iostream>
#include <string>
#include <set>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> unique_letters;

    for (char c : s) {
        unique_letters.insert(toupper(c));
    }

    cout << unique_letters.size() << endl;

    return 0;
}