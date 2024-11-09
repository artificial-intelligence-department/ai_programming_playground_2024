#include <iostream>
using namespace std;

bool IsPalindrome(const string& line, int start, int end) {
    bool tmp = true;  
    if (start < end) {
        if (line[start] == line[end]) {
            tmp = IsPalindrome(line, start + 1, end - 1);
        } else {
            tmp = false;
        }
    }
    return tmp;
}

bool IsPalindrome(int test_int) {
    string test = to_string(test_int);
    return IsPalindrome(test, 0, test.length() - 1);
}

void Print(bool res, const string& type) {
    if (res) {
        cout << type << " є паліндромом!" << endl;
    } else {
        cout << type << " не є паліндромом..." << endl;
    }
}

int main() {
    int test_int;
    cout << "Введіть число для перевірки: ";
    cin >> test_int;
    bool res_int = IsPalindrome(test_int);
    Print(res_int, "Число");

    string test_str;
    cout << "Введіть слово для перевірки: ";
    cin >> test_str;
    bool res_str = IsPalindrome(test_str, 0, test_str.length() - 1);
    Print(res_str, "Слово");

    return 0;
}
