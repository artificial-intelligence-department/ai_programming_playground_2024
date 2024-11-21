#include <iostream>
#include <string>

using namespace std;

int main() {
    // Читання вхідної стрічки
    string s;
    cin >> s;

    // Якщо стрічка порожня (на всяк випадок, хоча обмеження гарантують, що довжина буде ? 1)
    if (s.empty()) {
        cout << 0 << endl;
        return 0;
    }

    // Змінна для зберігання результату компресії
    string compressed = "";

    int n = s.size();
    int i = 0;

    while (i < n) {
        char currentChar = s[i];
        int count = 1;

        // Підрахунок кількості однакових символів підряд
        while (i + 1 < n && s[i + 1] == currentChar) {
            count++;
            i++;
        }

        // Додавання символу та кількості повторів (якщо більше одного)
        compressed += currentChar;
        if (count > 1) {
            compressed += to_string(count);
        }

        // Переходимо до наступного символу
        i++;
    }

    // Виведення результату
    cout << compressed << endl;

    return 0;
}

//aaabbcddd
