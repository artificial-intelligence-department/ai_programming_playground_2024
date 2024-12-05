#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

struct Stadium {
    char name[50];
    char address[100];  
    int capacity;      
    char sport[50];    
};

void createBinaryFile(const char* filename) {
    ofstream outFile(filename, ios::binary);

    if (!outFile) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    Stadium stadiums[] = {
        {"Olympic Stadium", "Kyiv, Ukraine", 70000, "Football"},
        {"Stamford Bridge", "London, England", 40000, "Football"},
        {"Camp Nou", "Barcelona, Spain", 99000, "Football"}
    };

    for (const auto& stadium : stadiums) {
        outFile.write(reinterpret_cast<const char*>(&stadium), sizeof(stadium));
    }

    outFile.close();
    cout << "Дані успішно записані в двійковий файл." << endl;
}

void printBinaryFile(const char* filename) {
    ifstream inFile(filename, ios::binary);

    if (!inFile) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    Stadium stadium;
    while (inFile.read(reinterpret_cast<char*>(&stadium), sizeof(stadium))) {
        cout << "Назва: " << stadium.name << endl;
        cout << "Адреса: " << stadium.address << endl;
        cout << "Місткість: " << stadium.capacity << endl;
        cout << "Види спорту: " << stadium.sport << endl << endl;
    }

    inFile.close();
}

void addStadiums(const char* filename, int index, const Stadium& newStadium1, const Stadium& newStadium2) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    vector<Stadium> stadiums;
    Stadium stadium;

    while (inFile.read(reinterpret_cast<char*>(&stadium), sizeof(stadium))) {
        stadiums.push_back(stadium);
    }
    inFile.close();

    if (index < 0 || index >= stadiums.size()) {
        cerr << "Невірний індекс!" << endl;
        return;
    }

    stadiums.insert(stadiums.begin() + index + 1, newStadium2);
    stadiums.insert(stadiums.begin() + index + 1, newStadium1);

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return;
    }

    for (const auto& s : stadiums) {
        outFile.write(reinterpret_cast<const char*>(&s), sizeof(s));
    }

    outFile.close();
    cout << "Два нових стадіони успішно додані." << endl;
}

void deleteStadiumByName(const char* filename, const char* stadiumName) {
    ifstream inFile(filename, ios::binary);

    if (!inFile) {
        cerr << "Не вдалося відкрити файл для читання!" << endl;
        return;
    }

    ofstream tempFile("temp.bin", ios::binary);

    Stadium stadium;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&stadium), sizeof(stadium))) {
        if (strcmp(stadium.name, stadiumName) != 0) {
            tempFile.write(reinterpret_cast<const char*>(&stadium), sizeof(stadium));
        } else {
            found = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (!found) {
        cerr << "Стадіон з такою назвою не знайдений!" << endl;
        remove("temp.bin");
        return;
    }

    remove(filename);
    rename("temp.bin", filename);

    cout << "Стадіон з назвою '" << stadiumName << "' успішно видалено." << endl;
}

int main() {
    const char* filename = "stadiums.bin";

    createBinaryFile(filename);

    cout << "Вміст двійкового файлу:" << endl;
    printBinaryFile(filename);

    int index;
    cout << "Введіть індекс, після якого додати два нових стадіони: ";
    cin >> index;

    cin.ignore();
    Stadium newStadium1;
    cout << "Введіть назву першого нового стадіону: ";
    cin.getline(newStadium1.name, 50);
    cout << "Введіть адресу першого нового стадіону: ";
    cin.getline(newStadium1.address, 100);
    cout << "Введіть місткість першого нового стадіону: ";
    cin >> newStadium1.capacity;
    cin.ignore();
    cout << "Введіть види спорту для першого нового стадіону: ";
    cin.getline(newStadium1.sport, 50);

    Stadium newStadium2;
    cout << "Введіть назву другого нового стадіону: ";
    cin.getline(newStadium2.name, 50);
    cout << "Введіть адресу другого нового стадіону: ";
    cin.getline(newStadium2.address, 100);
    cout << "Введіть місткість другого нового стадіону: ";
    cin >> newStadium2.capacity;
    cin.ignore();
    cout << "Введіть види спорту для другого нового стадіону: ";
    cin.getline(newStadium2.sport, 50);

    addStadiums(filename, index, newStadium1, newStadium2);

    cout << "\nВміст після додавання двох нових елементів:" << endl;
    printBinaryFile(filename);

    char stadiumName[50];
    cout << "\nВведіть назву стадіону для видалення: ";
    cin.getline(stadiumName, 50);

    deleteStadiumByName(filename, stadiumName);

    cout << "\nВміст після видалення елемента:" << endl;
    printBinaryFile(filename);

    return 0;
}