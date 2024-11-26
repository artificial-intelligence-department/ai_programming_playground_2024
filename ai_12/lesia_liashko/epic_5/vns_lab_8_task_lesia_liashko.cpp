#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Stadium {
    char name[50];       
    char address[100];   
    int capacity;        
    char sports[50];     
};

void writeToFile(const char* filename, const vector<Stadium>& stadiums) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка запису у файл!\n";
        return;
    }
    for (const auto& stadium : stadiums) {
        file.write((char*)&stadium, sizeof(Stadium));
    }
    file.close();
}

void printFromFile(const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка читання файлу!\n";
        return;
    }
    Stadium stadium;
    while (file.read((char*)&stadium, sizeof(Stadium))) {
        cout << "Назва: " << stadium.name 
             << ", Адреса: " << stadium.address 
             << ", Місткість: " << stadium.capacity 
             << ", Види спорту: " << stadium.sports << endl;
    }
    file.close();
}

void deleteFromFile(const char* filename, const char* nameToDelete) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка читання файлу!\n";
        return;
    }
    vector<Stadium> stadiums;
    Stadium stadium;
    while (file.read((char*)&stadium, sizeof(Stadium))) {
        if (strcmp(stadium.name, nameToDelete) != 0) {
            stadiums.push_back(stadium);
        }
    }
    file.close();

    writeToFile(filename, stadiums);
}

void addToFileAfter(const char* filename, int index, const Stadium& s1, const Stadium& s2) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cout << "Помилка читання файлу!\n";
        return;
    }
    vector<Stadium> stadiums;
    Stadium stadium;
    while (file.read((char*)&stadium, sizeof(Stadium))) {
        stadiums.push_back(stadium);
    }
    file.close();

    if (index >= 0 && index < stadiums.size()) {
        stadiums.insert(stadiums.begin() + index + 1, s1);
        stadiums.insert(stadiums.begin() + index + 2, s2);
        writeToFile(filename, stadiums);
    } else {
        cout << "Невірний номер елемента!\n";
    }
}


Stadium inputStadium() {
    Stadium stadium;
    cin.ignore(); 
    cout << "Введіть назву: ";
    cin.getline(stadium.name, 50);
    cout << "Введіть адресу: ";
    cin.getline(stadium.address, 100);
    cout << "Введіть місткість: ";
    cin >> stadium.capacity;
    cin.ignore(); 
    cout << "Введіть вид спорту: ";
    cin.getline(stadium.sports, 50);
    return stadium;
}

int main() {
    const char* filename = "stadiums.bin";
    vector<Stadium> stadiums;

    int n;
    cout << "Скільки стадіонів додати? ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Стадіон " << i + 1 << ":\n";
        stadiums.push_back(inputStadium());
    }
    writeToFile(filename, stadiums);

    cout << "\nПоточний список стадіонів:\n";
    printFromFile(filename);

    cout << "\nВведіть назву стадіону для видалення: ";
    char nameToDelete[50];
    cin.ignore();
    cin.getline(nameToDelete, 50);
    deleteFromFile(filename, nameToDelete);
    cout << "\nСписок після видалення:\n";
    printFromFile(filename);

    cout << "\nВведіть номер стадіону, після якого додати нові: ";
    int index;
    cin >> index;
    cout << "Перший новий стадіон:\n";
    Stadium newStadium1 = inputStadium();
    cout << "Другий новий стадіон:\n";
    Stadium newStadium2 = inputStadium();
    addToFileAfter(filename, index - 1, newStadium1, newStadium2);
    
    cout << "\nФінальний список стадіонів:\n";
    printFromFile(filename);

    return 0;
}
