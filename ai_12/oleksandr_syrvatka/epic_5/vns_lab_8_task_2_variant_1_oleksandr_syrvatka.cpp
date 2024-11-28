#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Abiturient {
    char surname[50];
    char name[50];
    char patronymic[50];
    int birthYear;
    int examGrades[3];
    double avgDiplomaScore;
};

// Масив для 5 абітурієнтів, ініціалізованих в коді
Abiturient abiturients[5] = {
    {"Ivanov", "Ivan", "Ivanovich", 2001, {180, 175, 190}, 4.5},
    {"Petrov", "Petro", "Petrovich", 2000, {185, 190, 180}, 4.6},
    {"Sidorov", "Sidir", "Sidorovich", 1999, {160, 170, 165}, 4.3},
    {"Kovalenko", "Kostyantyn", "Anatoliyovych", 2002, {190, 185, 200}, 4.8},
    {"Melnyk", "Mykola", "Volodymyrovych", 2003, {175, 165, 180}, 4.2}
};

// Функція для запису абітурієнтів у файл
void writeToFile(const char* filename, Abiturient* abits, size_t count) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    fwrite(abits, sizeof(Abiturient), count, file);  // Записуємо абітурієнтів у файл

    fclose(file);
}

// Функція для читання абітурієнтів з файлу
void readFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Abiturient ab;
    while (fread(&ab, sizeof(Abiturient), 1, file)) {
        cout << "Surname: " << ab.surname << ", Name: " << ab.name << ", Patronymic: " << ab.patronymic << endl;
        cout << "Birth Year: " << ab.birthYear << endl;
        cout << "Entrance Exam Grades: ";
        for (int i = 0; i < 3; ++i) {
            cout << ab.examGrades[i] << " ";
        }
        cout << "\nAverage Diploma Score: " << ab.avgDiplomaScore << endl << endl;
    }

    fclose(file);
}

// Функція для знищення абітурієнта за номером
void deleteAbiturient(const char* filename, int indexToDelete) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    FILE* tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        cerr << "Error opening temporary file for writing!" << endl;
        fclose(file);
        return;
    }

    Abiturient ab;
    int index = 0;
    while (fread(&ab, sizeof(Abiturient), 1, file)) {
        if (index != indexToDelete) {
            fwrite(&ab, sizeof(Abiturient), 1, tempFile);  // Копіюємо всі елементи, окрім того, який треба видалити
        }
        index++;
    }

    fclose(file);
    fclose(tempFile);

    // Видаляємо старий файл і перейменовуємо тимчасовий файл в основний
    remove(filename);
    rename("temp.dat", filename);

    cout << "Abiturient deleted successfully!" << endl;
}

// Функція для додавання абітурієнта після зазначеного прізвища
void addAbiturientAfterSurname(const char* filename, const char* surname) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    FILE* tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        cerr << "Error opening temporary file for writing!" << endl;
        fclose(file);
        return;
    }

    Abiturient ab;
    bool surnameFound = false;
    while (fread(&ab, sizeof(Abiturient), 1, file)) {
        fwrite(&ab, sizeof(Abiturient), 1, tempFile);  // Копіюємо елемент в тимчасовий файл

        // Якщо знайдений абітурієнт з таким прізвищем, додаємо нового
        if (strcmp(ab.surname, surname) == 0) {
            Abiturient newAbiturient;
            cout << "Enter surname: ";
            cin >> newAbiturient.surname;
            cout << "Enter name: ";
            cin >> newAbiturient.name;
            cout << "Enter patronymic: ";
            cin >> newAbiturient.patronymic;
            cout << "Enter birth year: ";
            cin >> newAbiturient.birthYear;
            cout << "Enter entrance exam grades (3): ";
            for (int i = 0; i < 3; ++i) {
                cin >> newAbiturient.examGrades[i];
            }
            cout << "Enter average diploma score: ";
            cin >> newAbiturient.avgDiplomaScore;

            fwrite(&newAbiturient, sizeof(Abiturient), 1, tempFile);  // Додаємо нового абітурієнта після знайденого
            surnameFound = true;
        }
    }

    fclose(file);
    fclose(tempFile);

    if (!surnameFound) {
        cout << "No abiturient found with the surname " << surname << endl;
        return;
    }

    // Видаляємо старий файл і перейменовуємо тимчасовий файл в основний
    remove(filename);
    rename("temp.dat", filename);

    cout << "Abiturient added successfully after " << surname << "!" << endl;
}

int main() {
    const char* filename = "abiturients.dat";

    // Спочатку записуємо 5 абітурієнтів у файл
    writeToFile(filename, abiturients, 5);

    // Читаємо вміст файлу і виводимо його
    cout << "File contents before any operation:\n";
    readFromFile(filename);

    // Запит про знищення абітурієнта
    int indexToDelete;
    cout << "Enter the index of the abiturient to delete: ";
    cin >> indexToDelete;
    deleteAbiturient(filename, indexToDelete);

    // Запит про додавання абітурієнта після певного прізвища
    char surname[50];
    cout << "Enter the surname after which you want to add a new abiturient: ";
    cin >> surname;
    addAbiturientAfterSurname(filename, surname);

    // Після всіх операцій виводимо вміст файлу
    cout << "\nFile contents after all operations:\n";
    readFromFile(filename);

    return 0;
}
