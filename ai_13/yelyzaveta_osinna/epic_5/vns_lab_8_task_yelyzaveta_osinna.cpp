#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Опис структури "Людина"
struct Person {
    char surname[50];
    char name[50];
    char patronymic[50];
    int birthYear;
    int height;
    int weight;
};

// Функція для створення двійкового файлу
void createFile(const string& filename, const vector<Person>& people) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    for (const auto& person : people) {
        file.write(reinterpret_cast<const char*>(&person), sizeof(Person));
    }
    file.close();
}

// Функція для друку вмісту двійкового файлу
void printFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }
    Person person;
    cout << "Вміст файлу:" << endl;
    while (file.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        cout << person.surname << " " << person.name << " " << person.patronymic
             << ", Рік народження: " << person.birthYear
             << ", Ріст: " << person.height << " см"
             << ", Вага: " << person.weight << " кг" << endl;
    }
    file.close();
}

// Функція для видалення елементів за заданим критерієм
void deleteByHeightAndWeight(const string& filename, int height, int weight) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }

    vector<Person> people;
    Person person;

    // Зчитуємо всі елементи, які не відповідають критеріям
    while (file.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        if (person.height != height || person.weight != weight) {
            people.push_back(person);
        }
    }
    file.close();

    // Перезаписуємо файл без видалених елементів
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    for (const auto& p : people) {
        outFile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
    }
    outFile.close();
}

// Функція для додавання елемента після заданого прізвища
void addAfterSurname(const string& filename, const string& targetSurname, const Person& newPerson) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }

    vector<Person> people;
    Person person;

    // Зчитуємо всі елементи
    while (file.read(reinterpret_cast<char*>(&person), sizeof(Person))) {
        people.push_back(person);
        // Додаємо нового елемента після знайденого прізвища
        if (targetSurname == person.surname) {
            people.push_back(newPerson);
        }
    }
    file.close();

    // Перезаписуємо файл з оновленими даними
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    for (const auto& p : people) {
        outFile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
    }
    outFile.close();
}

// Головна функція для тестування
int main() {
    string filename = "people.dat";

    // Початкові дані
    vector<Person> people = {
        {"Іваненко", "Іван", "Іванович", 1985, 180, 75},
        {"Петренко", "Петро", "Петрович", 1990, 175, 80},
        {"Сидоренко", "Олексій", "Олексійович", 2000, 165, 60},
    };

    // Створення файлу
    createFile(filename, people);

    // Виведення вмісту файлу
    printFile(filename);

    // Видалення елементів з ростом 175 і вагою 80
    deleteByHeightAndWeight(filename, 175, 80);
    cout << "\nПісля видалення елементів із ростом 175 і вагою 80:" << endl;
    printFile(filename);

    // Додавання нового елемента після елемента з прізвищем "Іваненко"
    Person newPerson = {"Новаченко", "Наталія", "Володимирівна", 1995, 170, 65};
    addAfterSurname(filename, "Іваненко", newPerson);
    cout << "\nПісля додавання нового елемента після 'Іваненко':" << endl;
    printFile(filename);

    return 0;
}
