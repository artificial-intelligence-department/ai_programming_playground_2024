#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

struct EMPLOYEE {
    char name[40];
    char surname[40];
    char last_name[40];
    char position[40];
    int birth_year;
    float salary;
};

const int N = 2; // Кількість співробітників для створення файлу

// Створення файлу з співробітниками
void create_file(const char* filename) {
    FILE* file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        cerr << "ERROR while opening file for writing." << endl;
        exit(1);
    }

    EMPLOYEE emp;

    for (int i = 0; i < N; i++) {
        cout << "Name: "; cin >> emp.name;
        cout << "Surname: "; cin >> emp.surname;
        cout << "Last Name: "; cin >> emp.last_name;
        cout << "Position: "; cin >> emp.position;
        cout << "Birth Year: "; cin >> emp.birth_year;
        cout << "Salary: "; cin >> emp.salary;

        fwrite(&emp, sizeof(EMPLOYEE), 1, file);
        if (ferror(file)) {
            cerr << "ERROR while writing in file." << endl;
            exit(2);
        }
    }
    fclose(file);
}

// Друк файлу
void print_file(const char* filename) {
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "ERROR while opening file for reading." << endl;
        exit(3);
    }

    EMPLOYEE emp;
    cout << "File contains:" << endl;

    while (fread(&emp, sizeof(EMPLOYEE), 1, file) == 1) {
        cout << emp.name << " " << emp.surname << " " << emp.last_name << " "
             << emp.position << " " << emp.birth_year << " " << emp.salary << endl;
    }

    fclose(file);
}

// Додавання нового співробітника в кінець файлу
void add_employee(const char* filename, EMPLOYEE newEmp) {
    FILE* file;
    file = fopen(filename, "ab");
    if (file == NULL) {
        cerr << "ERROR while opening file for writing." << endl;
        exit(4);
    }

    fwrite(&newEmp, sizeof(EMPLOYEE), 1, file);
    if (ferror(file)) {
        cerr << "ERROR writing while adding employee." << endl;
        exit(5);
    }

    fclose(file);
}

// Додавання співробітника після співробітника з певним прізвищем
void add_employee_after(const char* filename, const char* surname) {
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "ERROR while opening file for reading." << endl;
        exit(4);
    }

    FILE* temp_file;
    temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        cerr << "ERROR while creating temporary file" << endl;
        fclose(file);
        exit(5);
    }

    EMPLOYEE emp;
    bool found = false;

    while (fread(&emp, sizeof(EMPLOYEE), 1, file) == 1) {
        fwrite(&emp, sizeof(EMPLOYEE), 1, temp_file); // записуємо поточний запис
        if (strcmp(emp.surname, surname) == 0 && !found) {
            // Додаємо нового співробітника після знайденого
            fwrite(&emp, sizeof(EMPLOYEE), 1, temp_file);
            found = true;
        }
    }

    fclose(file);
    fclose(temp_file);


    if (found) {
        remove(filename);
        rename("temp.dat", filename);
        cout << "Employee added after " << surname << endl;
    } else {
        cout << "Employee with surname " << surname << " isn't found." << endl;
        remove("temp.dat");
    }
}

// Видалення співробітника за прізвищем
void delete_employee_with_surname(const char* filename, const char* surname) {
    FILE* file;
    file = fopen(filename, "rb");
    if (file == NULL) {
        cerr << "ERROR while opening file for deleting." << endl;
        exit(6);
    }

    FILE* temp_file;
    temp_file = fopen("temp.dat", "wb");
    if (temp_file == NULL) {
        cerr << "ERROR while creating temporary file" << endl;
        fclose(file);
        exit(7);
    }

    EMPLOYEE emp;
    bool deleted_surname = false;
    while (fread(&emp, sizeof(EMPLOYEE), 1, file)) {
        if (strcmp(emp.surname, surname) == 0) {
            deleted_surname = true;
        } else {
            fwrite(&emp, sizeof(EMPLOYEE), 1, temp_file);
        }
    }

    fclose(file);
    fclose(temp_file);

    if (deleted_surname) {
        remove(filename);
        rename("temp.dat", filename);
        cout << "Employee " << surname << " removed from file." << endl;
    } else {
        cout << "Employee with surname " << surname << " isn't found." << endl;
        remove("temp.dat");
    }
}

int main() {
    const char* filename = "employees.dat";

    // Створення файлу
    create_file(filename);

    // Друк вмісту файлу
    print_file(filename);

    // Додавання нового співробітника
    EMPLOYEE newEmp =  {"Danulo", "Siatetski", "Romanovych", "Student", 2007, 500};
    add_employee(filename, newEmp);

    // Видалення співробітника за прізвищем
    delete_employee_with_surname(filename, "Faryna");

    // Друк вмісту файлу після змін
    cout << "\nAfter deleting employee surname and adding new employee: \n";
    print_file(filename);

    return 0;
}
