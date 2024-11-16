#include <iostream>
#include <string>

using namespace std;

int main() {
    //створюмо змінну для рядка юзера
    string s;
    cin >> s;

    //створюмо змінні для стисненого строки та розміру 
    string compressed;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        char currentChar = s[i];
        int count = 1;

        //рахуємо кількість однвкових літер під ряд
        while (i+1 < n && s[i + 1] == currentChar) {
            ++count;
            ++i;
        }

        //записуємо у нову строку літери і їх кількість
        compressed += currentChar;
        if (count > 1) {
            compressed += to_string(count);
        }
    }
    
    //виводимо кінцевий результат
    cout << compressed << endl;
    return 0;
}
