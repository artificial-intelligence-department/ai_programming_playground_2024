#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayFileContent(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "Вміст файлу \"" << filename << "\":\n";
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    } else {
        cout << "Не вдалося відкрити файл \"" << filename << "\" для читання.\n";
    }
}

int main() {
    string filename, text;
    char choice;

    do {
        cout << "Введіть назву файлу (з розширенням, наприклад, file.txt): ";
        cin >> filename;

        cout << "Файл \"" << filename << "\" вже існує? (y/n): ";
        cin >> choice;

        ofstream file;
        if (choice == 'y' || choice == 'Y') {
            file.open(filename, ios::app);
            if (!file.is_open()) {
                cout << "Помилка відкриття файлу \"" << filename << "\".\n";
                continue;
            }
            cout << "Введіть текст для додавання у файл: ";
        } else {
            file.open(filename); 
            if (!file.is_open()) {
                cout << "Помилка створення файлу \"" << filename << "\".\n";
                continue;
            }
            cout << "Введіть текст для запису у новий файл: ";
        }

        cin.ignore(); 
        getline(cin, text);

        file << text << "\n";
        file.close();
        cout << "Текст успішно записано у файл \"" << filename << "\".\n";

        displayFileContent(filename);

        cout << "Бажаєте працювати з іншим файлом? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Програма завершена.\n";
    return 0;
}
