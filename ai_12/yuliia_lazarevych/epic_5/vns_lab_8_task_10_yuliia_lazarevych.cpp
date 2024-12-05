#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

//структура "Information"
struct Information {
    char medium[50];
    int volume;
    char title[100];
    char author[50];
};

//допоміжна функція для створення об'єктів в 'Інформації'
Information create_information(const char* medium, int volume, const char* title, const char* author) {
    Information info;
    strncpy(info.medium, medium, sizeof(info.medium) - 1);
    info.medium[sizeof(info.medium) - 1] = '\0';

    info.volume = volume;

    strncpy(info.title, title, sizeof(info.title) - 1);
    info.title[sizeof(info.title) - 1] = '\0';

    strncpy(info.author, author, sizeof(info.author) - 1);
    info.author[sizeof(info.author) - 1] = '\0';

    return info;
}

//створюємо бінарний файл
void create_file(const string& filename, const vector<Information>& elements) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Cannot open file for writing.\n";
        return;
    }
    for (const auto& element : elements) {
        file.write(reinterpret_cast<const char*>(&element), sizeof(Information));
    }
    file.close();
}

//виводимо складові файлу
void print_file(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error: Cannot open file for reading.\n";
        return;
    }
    Information element;
    while (file.read(reinterpret_cast<char*>(&element), sizeof(Information))) {
        cout << "Medium: " << element.medium
             << ", Volume: " << element.volume
             << ", Title: " << element.title
             << ", Author: " << element.author << "\n";
    }
    file.close();
}

int main() {
    string filename = "information.bin";

    //ініціалізуємо вектор використовуючи допоміжну функцію
    vector<Information> elements = {
        create_information("CD", 700, "Learning C++", "Bjarne Stroustrup"),
        create_information("USB", 16000, "C++ Primer", "Stanley Lippman"),
        create_information("HDD", 500000, "Effective C++", "Scott Meyers")
    };

    create_file(filename, elements);
    cout << "Contents of the initial file:\n";
    print_file(filename);

    return 0;
}
