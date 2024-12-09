#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Структура "Людина"
struct Person {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char address[100];
    char phoneNumber[20];
    int age;
};

// Функція для заповнення однієї структури
void fillPerson(Person& p) {
    cout << "Введіть прізвище: ";
    cin >> p.lastName;
    cout << "Введіть ім'я: ";
    cin >> p.firstName;
    cout << "Введіть по батькові: ";
    cin >> p.middleName;
    cout << "Введіть домашню адресу: ";
    cin.ignore(); // Очищаємо буфер
    cin.getline(p.address, 100);
    cout << "Введіть номер телефону: ";
    cin >> p.phoneNumber;
    cout << "Введіть вік: ";
    cin >> p.age;
}

// Функція для виведення даних про людину
void printPerson(const Person& p) {
    cout << "Прізвище: " << p.lastName << "\nІм'я: " << p.firstName << "\nПо батькові: " << p.middleName 
         << "\nАдреса: " << p.address << "\nТелефон: " << p.phoneNumber << "\nВік: " << p.age << "\n------------------------" << endl;
}

// Функція для запису структури у файл
void writeToFile(const char* filename, const Person& p) {
    ofstream outFile(filename, ios::binary | ios::app);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
    outFile.close();
}

// Функція для читання всіх елементів з файлу
void readFromFile(const char* filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }
    Person p;
    while (inFile.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
        printPerson(p);
    }
    inFile.close();
}

// Функція для видалення людей із заданим віком
void removeByAge(const char* filename, int ageToRemove) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cerr << "Помилка відкриття тимчасового файлу для запису!" << endl;
        return;
    }

    Person p;
    while (inFile.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
        if (p.age != ageToRemove) {
            tempFile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename);
    rename("temp.dat", filename);
    cout << "Елементи з віком " << ageToRemove << " успішно видалено." << endl;
}

// Функція для додавання нового елемента після заданого
void addAfterPerson(const char* filename, int personNumber, const Person& newPerson) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Помилка відкриття файлу для читання!" << endl;
        return;
    }

    ofstream tempFile("temp.dat", ios::binary);
    if (!tempFile) {
        cerr << "Помилка відкриття тимчасового файлу для запису!" << endl;
        return;
    }

    Person p;
    int currentIndex = 0;
    while (inFile.read(reinterpret_cast<char*>(&p), sizeof(Person))) {
        tempFile.write(reinterpret_cast<const char*>(&p), sizeof(Person));
        currentIndex++;
        if (currentIndex == personNumber) {
            tempFile.write(reinterpret_cast<const char*>(&newPerson), sizeof(Person));
        }
    }

    inFile.close();
    tempFile.close();

    remove(filename);
    rename("temp.dat", filename);
    cout << "Нова людина додана після " << personNumber << "-го елемента." << endl;
}

// Функція для очищення файлу
void clearFile(const char* filename) {
    ofstream outFile(filename, ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Помилка відкриття файлу для очищення!" << endl;
        return;
    }
    outFile.close();
    cout << "Файл успішно очищений." << endl;
}

// Функція для видалення файлу
void deleteFile(const char* filename) {
    if (remove(filename) != 0) {
        cerr << "Помилка при видаленні файлу!" << endl;
    } else {
        cout << "Файл успішно видалено." << endl;
    }
}

int main() {
    const char* filename = "people.dat";

    // Введення кількості людей, яких хочемо додати в файл
    int count;
    cout << "Введіть кількість людей: ";
    cin >> count;

    // Додаємо людей у файл
    for (int i = 0; i < count; i++) {
        Person p;
        cout << "Введіть дані для " << i + 1 << "-ї людини:" << endl;
        fillPerson(p);
        writeToFile(filename, p);
    }

    // Читання всіх елементів з файлу
    cout << "\nВміст файлу:\n";
    readFromFile(filename);

    // Видалення людей із заданим віком
    int ageToRemove;
    cout << "\nВведіть вік для видалення: ";
    cin >> ageToRemove;
    removeByAge(filename, ageToRemove);

    // Читання всіх елементів після видалення
    cout << "\nВміст файлу після видалення:\n";
    readFromFile(filename);

    // Додавання нового елемента
    Person newPerson;
    cout << "\nВведіть дані для нової людини, яку потрібно додати після певного елемента:" << endl;
    fillPerson(newPerson);
    int personNumber;
    cout << "Введіть номер елемента після якого потрібно додати нового: ";
    cin >> personNumber;
    addAfterPerson(filename, personNumber, newPerson);

    // Читання всіх елементів після додавання
    cout << "\nВміст файлу після додавання:\n";
    readFromFile(filename);

    // Очищення файлу
    char choice;
    cout << "\nЧи хочете ви очистити файл? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        clearFile(filename);
    }

    // Видалення файлу
    cout << "\nЧи хочете ви видалити файл? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        deleteFile(filename);
    }

    return 0;
}
