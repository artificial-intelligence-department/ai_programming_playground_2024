#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum FileOpResult
{
    Success, Failure
};

FileOpResult copy_file(const char* from, char* to) {

    ifstream file_from(from); // Відкрити файл для читання

    if (!file_from) {
        cerr << "Error opening file!" << endl;
        return Failure;
    }

    ofstream file_to(to, std::ios::out); //cтворює файл або очищає і дозволяє редагувати то в С форматі

    if (!file_to) {
        cerr << "Error opening file!" << endl;
        return Failure;
    }

    string line;
    while (getline(file_from, line)) { 
        file_to << line << endl; 
    }
    return Success;
}

int main() {
    char name[50];
    cout << "Введіть назву нового файла куди копіювати: ";
    cin.getline(name, 50);
    copy_file("Dati.txt", name);

    FileOpResult res = copy_file("Dati.txt", name);
    if(res == Success)
    {
        cout << "Все успішно" << endl;
    }
    else
    {
        cout << "Помилка" << endl;
    }

    return 0;
}