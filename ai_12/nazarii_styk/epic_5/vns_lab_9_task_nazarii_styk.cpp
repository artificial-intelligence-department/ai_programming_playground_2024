// Variant 19
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція для перевірки, чи є символ приголосним
bool isConsonant(char c) 
{
    c = tolower(c); // Переводимо в нижній регістр
    return (c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() 
{
    ifstream fileF1("F1.txt"); // Вхідний файл
    ofstream fileF2("F2.txt"); // Вихідний файл

    if (!fileF1.is_open() || !fileF2.is_open()) 
    {
        cout << "Не вдалося відкрити файли!" << endl;
        return 1;
    }

    string line;
    string firstWord;

    // Зчитуємо перший рядок і отримуємо перше слово
    if (getline(fileF1, line)) 
    {
        size_t pos = line.find(' ');
        if (pos != string::npos) 
        {
            firstWord = line.substr(0, pos); // Зберігаємо перше слово
        } 
        else 
        {
            firstWord = line; // Якщо в рядку лише одне слово
        }
    }

    // Читаємо інші рядки та записуємо в F2, якщо немає співпадінь з першим словом
    while (getline(fileF1, line)) 
    {
        bool containsFirstWord = false;
        size_t pos = 0;

        // Шукаємо слова в рядку
        while ((pos = line.find(' ', pos)) != string::npos) 
        {
            string word = line.substr(0, pos);
            if (word == firstWord) 
            {
                containsFirstWord = true;
                break;
            }
            line.erase(0, pos + 1);
        }

        // Якщо не містить перше слово, записуємо рядок у F2
        if (!containsFirstWord) 
        {
            fileF2 << line << endl;
        }
    }

    // Закриваємо файли
    fileF1.close();
    fileF2.close();

    // Відкриваємо файл F2 для підрахунку приголосних
    ifstream fileF2ForCounting("F2.txt");

    if (!fileF2ForCounting.is_open()) {
        cout << "Не вдалося відкрити файл F2 для підрахунку приголосних!" << endl;
        return 1;
    }

    int consonantCount = 0;
    // Зчитуємо перший рядок з F2
    if (getline(fileF2ForCounting, line)) 
    {
        for (char c : line) 
        {
            if (isConsonant(c)) 
            {
                consonantCount++;
            }
        }
    }

    cout << "Кількість приголосних в першому рядку файлу F2: " << consonantCount << endl;

    fileF2ForCounting.close();

    return 0;
}

// 1) Скопіювати з файлу F1 у файл F2 всі рядки, у яких немає слів, що збігаються з першим словом.
// 2) Визначити кількість приголосних букв у першому рядку файлу F2.