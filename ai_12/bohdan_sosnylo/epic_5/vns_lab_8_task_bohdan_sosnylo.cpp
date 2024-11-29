#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

struct Human {
    char surname[50];
    char name[50];
    char patronymic[50];
    char address[100];
    char phone[20];
    int age;
};

void inputHumans(vector<Human>& humans) {
    int count;
    cout << "Введіть кількість людей: ";
    cin >> count;
    cin.ignore(); 

    for (int i = 0; i < count; ++i) {
        Human human;
        cout << "\nВведіть дані про людину " << (i + 1) << ":" << endl;

        cout << "Прізвище: ";
        cin.getline(human.surname, 50);
        cout << "Ім'я: ";
        cin.getline(human.name, 50);
        cout << "По-батькові: ";
        cin.getline(human.patronymic, 50);
        cout << "Адреса: ";
        cin.getline(human.address, 100);
        cout << "Телефон: ";
        cin.getline(human.phone, 20);
        cout << "Вік: ";
        cin >> human.age;
        cin.ignore(); 
        humans.push_back(human);
    }
}

void createBinaryFile(const string& filename, const vector<Human>& humans) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }
    for (const auto& human : humans) {
        file.write(reinterpret_cast<const char*>(&human), sizeof(Human));
    }
    file.close();
}


void printBinaryFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    Human human;
    while (file.read(reinterpret_cast<char*>(&human), sizeof(Human))) {
        cout << human.surname << " " << human.name << " " << human.patronymic 
                  << ", " << human.address << ", " << human.phone 
                  << ", вік: " << human.age << endl;
    }

    file.close();
}


void deleteByAge(const string& filename, int ageToDelete) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    if (!inFile || !outFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    Human human;
    while (inFile.read(reinterpret_cast<char*>(&human), sizeof(Human))) {
        if (human.age != ageToDelete) {
            outFile.write(reinterpret_cast<const char*>(&human), sizeof(Human));
        }
    }

    inFile.close();
    outFile.close();
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}

// Функція для додавання запису після елемента з номером телефону
void addAfterPhone(const string& filename, const string& phone, const Human& newHuman) {
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.dat", ios::binary);
    if (!inFile || !outFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    Human human;
    while (inFile.read(reinterpret_cast<char*>(&human), sizeof(Human))) {
        outFile.write(reinterpret_cast<const char*>(&human), sizeof(Human));
        if (phone == human.phone) {
            outFile.write(reinterpret_cast<const char*>(&newHuman), sizeof(Human));
        }
    }

    inFile.close();
    outFile.close();
    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}

int main() {

    setlocale(LC_ALL, "uk_UA.UTF-8"); 
    
    string filename = "humans.dat";
    vector<Human> humans;

    inputHumans(humans);
    createBinaryFile(filename, humans);
    
    cout << "\nПочатковий вміст файлу:" << endl;
    printBinaryFile(filename);

    int ageToDelete;
    cout << "\nВведіть вік для видалення записів: ";
    cin >> ageToDelete;
    deleteByAge(filename, ageToDelete);

    cout << "\nПісля видалення записів із віком " << ageToDelete << ":" << endl;
    printBinaryFile(filename);

    Human newHuman;
    cout << "\nВведіть дані нового запису для додавання:\n";
    cin.ignore();
    cout << "Прізвище: "; cin.getline(newHuman.surname, 50);
    cout << "Ім'я: "; cin.getline(newHuman.name, 50);
    cout << "По-батькові: "; cin.getline(newHuman.patronymic, 50);
    cout << "Адреса: "; cin.getline(newHuman.address, 100);
    cout << "Телефон: "; cin.getline(newHuman.phone, 20);
    cout << "Вік: "; cin >> newHuman.age;

    string phoneToFind;
    cout << "\nВведіть номер телефону, після якого додати новий запис: ";
    cin >> phoneToFind;
    addAfterPhone(filename, phoneToFind, newHuman);

    cout << "\nПісля додавання нового запису телефону " << phoneToFind << ":" << endl;
    printBinaryFile(filename);

    return 0;
}