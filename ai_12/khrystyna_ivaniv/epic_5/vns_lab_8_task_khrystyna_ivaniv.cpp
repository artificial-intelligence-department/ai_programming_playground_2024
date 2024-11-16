#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Pupil
{
    char last_name[30];
    char first_name[30];
    char patronymic[30];
    int grade;
    char phone[15];
    int math;
    int physics;
    int ukrainian;
    int literature;

    bool two_low_gades() const
    {
        int low_count = 0;
        if (math < 3)
            low_count++;
        if (physics < 3)
            low_count++;
        if (ukrainian < 3)
            low_count++;
        if (literature < 3)
            low_count++;
        return low_count >= 2;
    }
};

// Функція для створення та запису даних у файл
void create_file(const string &filename, const vector<Pupil> &pupils)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Error: Cannot open file for writing.\n";
        return;
    }
    for (const auto &pupil : pupils)
    {
        file.write(reinterpret_cast<const char *>(&pupil), sizeof(Pupil));
    }
    file.close();
}

// Функція для виведення вмісту файлу
void print_file(const string &filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Error: Cannot open file for reading.\n";
        return;
    }
    Pupil pupil;
    while (file.read(reinterpret_cast<char *>(&pupil), sizeof(Pupil)))
    {
        cout << "Last name: " << pupil.last_name << ", First name: " << pupil.first_name
             << ", Patronomic: " << pupil.patronymic << ", Phone: " << pupil.phone 
             << "Math: " << pupil.math << ", Physics: " << pupil.physics
             << ", Ukrainian: " << pupil.ukrainian << ", Literature: " << pupil.literature << "\n";
    }
    file.close();
}

// Функція для видалення елементів, де є хоча б 2 оцінки менші за 3
void delete_low_grades(const string &fileName)
{
    ifstream in_file(fileName, ios::binary);
    if (!in_file)
    {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    vector<Pupil> pupils;
    Pupil pupil;
    while (in_file.read(reinterpret_cast<char *>(&pupil), sizeof(Pupil)))
    {
        if (!pupil.two_low_gades())
        {
            pupils.push_back(pupil);
        }
    }
    in_file.close();

    // Перезаписуємо файл з оновленими даними
    ofstream out_file(fileName, ios::binary | ios::trunc);
    if (!out_file)
    {
        cerr << "Помилка при відкритті файлу для запису!" << endl;
        return;
    }

    for (const auto &pupil : pupils)
    {
        out_file.write(reinterpret_cast<const char *>(&pupil), sizeof(Pupil));
    }

    out_file.close();
}

// Функція для додавання елементів у початок файлу
void add_to_file_at_start(const string& fileName, const Pupil& new_pupil) {
    // Читання всіх даних з файлу
    ifstream in_file(fileName, ios::binary);
    if (!in_file) {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    vector<Pupil> pupils;
    Pupil pupil;
    while (in_file.read(reinterpret_cast<char*>(&pupil), sizeof(Pupil))) {
        pupils.push_back(pupil);
    }
    in_file.close();

    // Запис нового елемента на початок файлу
    ofstream out_file(fileName, ios::binary | ios::trunc);
    if (!out_file) {
        cerr << "Помилка при відкритті файлу для запису!" << endl;
        return;
    }

    // Записуємо новий елемент на початок
    out_file.write(reinterpret_cast<const char*>(&new_pupil), sizeof(Pupil));

    // Потім записуємо всі інші елементи
    for (const auto& pupil : pupils) {
        out_file.write(reinterpret_cast<const char*>(&pupil), sizeof(Pupil));
    }

    out_file.close();
}
int main() {

    string fileName = "pupils.data";

    vector<Pupil> pupils = {
        {"Ivaniv", "Khrystyna", "Victorivna", 11, "123-456", 5, 5, 5, 5},
        {"Petrovy", "Petro", "Petrovych", 9, "987-654", 4, 5, 3, 4},
        {"Ivanovy", "Ivan", "Ivanovych", 11, "555-123", 2, 2, 4, 4}
    };

    create_file(fileName, pupils);

    cout << "Вміст файлу до змін:" << endl;
    print_file(fileName);

    delete_low_grades(fileName);
    cout << "Вміст файлу після видалення учнів з низькими оцінками:" << endl;
    print_file(fileName);

    Pupil new_pupil = {"Black", "John", "Stepanovych", 8, "111-222", 5, 5, 5, 5};
    add_to_file_at_start(fileName, new_pupil);
    cout << "Вміст файлу після додавання нового елемента на початок:" << endl;
    print_file(fileName);

    return 0;
}