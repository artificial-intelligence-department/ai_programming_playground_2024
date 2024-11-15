#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Stud {
    string name;
    string phone;
    string grp;
    int marks[3];
};

void addStud(vector<Stud>& studs) {
    Stud stud;
    cout << "Введіть повне ім'я: ";
    getline(cin, stud.name);
    cout << "Введіть номер телефону: ";
    getline(cin, stud.phone);
    cout << "Введіть групу: ";
    getline(cin, stud.grp);
    cout << "Введіть оцінки для трьох предметів через пробіл: ";
    cin >> stud.marks[0] >> stud.marks[1] >> stud.marks[2];
    cin.ignore();
    studs.push_back(stud);
}

void deleteStud(vector<Stud>& studs, const string& grpNum, float minAvg) {
    for (auto it = studs.begin(); it != studs.end(); ) {
        float average = (it->marks[0] + it->marks[1] + it->marks[2]) / 3.0;
        if (it->grp == grpNum && average < minAvg) {
            it = studs.erase(it);
        } else {
            ++it;
        }
    }
}

void saveToFile(const vector<Stud>& studs, const string& fileName) {
    ofstream file(fileName, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для запису." << endl;
        return;
    }
    for (const auto& stud : studs) {
        file << stud.name << '\n' << stud.phone << '\n' << stud.grp << '\n';
        for (int mark : stud.marks) {
            file << mark << ' ';
        }
        file << '\n';
    }
}

void loadFromFile(vector<Stud>& studs, const string& fileName) {
    ifstream file(fileName, ios::binary);
    if (!file) {
        cerr << "Помилка відкриття файлу для читання." << endl;
        return;
    }
    Stud stud;
    while (getline(file, stud.name)) {
        getline(file, stud.phone);
        getline(file, stud.grp);
        for (int& mark : stud.marks) {
            file >> mark;
        }
        file.ignore(); 
        studs.push_back(stud);
    }
}

void printStuds(const vector<Stud>& studs) {
    for (const auto& stud : studs) {
        cout << "Повне ім'я: " << stud.name << "\n";
        cout << "Номер телефону: " << stud.phone << "\n";
        cout << "Група: " << stud.grp << "\n";
        cout << "Оцінки: " << stud.marks[0] << ", " << stud.marks[1] << ", " << stud.marks[2] << "\n";
    }
}

int main() {
    vector<Stud> studs;
    string fileName = "students.txt";
    int choice;

    while (true) {
        cout << "1. Додати студента\n2. Видалити студента\n3. Вивести студентів\n4. Зберегти у файл\n5. Завантажити з файлу\n6. Вийти\nВведіть ваш вибір: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addStud(studs);
                break;
            case 2: {
                string grpNum;
                float minAvg;
                cout << "Введіть номер групи: ";
                getline(cin, grpNum);
                cout << "Введіть мінімальний середній бал: ";
                cin >> minAvg;
                cin.ignore();
                deleteStud(studs, grpNum, minAvg);
                break;
            }
            case 3:
                printStuds(studs);
                break;
            case 4:
                saveToFile(studs, fileName);
                break;
            case 5:
                loadFromFile(studs, fileName);
                break;
            case 6:
                return 0;
            default:
                cout << "Невірний вибір." << endl;
                break;
        }
    }

    return 0;
}
