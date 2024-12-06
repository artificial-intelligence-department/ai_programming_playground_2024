#include <iostream>
#include <string>
using namespace std;

int main() {
    const int MAX_LEN = 255; // Максимальна довжина рядка
    char s[MAX_LEN + 1]; // Буфер для вводу рядка (+1 для символу завершення '\0')

    cout << "Введіть рядок (до 255 символів), що закінчується крапкою:" << endl;
    cin.getline(s, MAX_LEN);

    string letters = ""; // Рядок для літер
    string digits = "";  // Рядок для цифр

    // Обробка рядка
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isalpha(s[i])) {
            letters += s[i]; // Додаємо до рядка літер
        } else if (isdigit(s[i])) {
            digits += s[i];  // Додаємо до рядка цифр
        }
    }

    // Об'єднання результату
    string result = letters + digits;
    cout << "Перетворений рядок: " << result << endl;

    return 0;
}
