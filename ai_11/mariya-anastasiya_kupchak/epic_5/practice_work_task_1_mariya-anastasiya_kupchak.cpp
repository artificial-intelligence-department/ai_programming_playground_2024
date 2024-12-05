#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write_to_file(char *name, char *content) 
{
    if (name == nullptr || content == nullptr) 
    {
        cerr << "Помилка: неправильні параметри." << endl;
        return Failure;
    }

    ofstream file(name);
    if (!file.is_open()) 
    {
        cerr << "Помилка: не вдалося відкрити файл для запису." << endl;
        return Failure;
    }

    file << content; 

    if (file.fail()) 
    {
        cerr << "Помилка: запис у файл не виконано." << endl;
        file.close();
        return Failure;
    }

    file.close();
    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to) 
{
    if (file_from == nullptr || file_to == nullptr) 
    {
        cerr << "Помилка: неправильні параметри." << endl;
        return Failure;
    }

    ifstream input(file_from, ios::binary);
    if (!input.is_open()) 
    {
        cerr << "Помилка: не вдалося відкрити файл-джерело." << endl;
        return Failure;
    }

    ofstream output(file_to, ios::binary);
    if (!output.is_open()) 
    {
        cerr << "Помилка: не вдалося відкрити файл-призначення." << endl;
        input.close();
        return Failure;
    }

    output << input.rdbuf();

    if (output.fail()) 
    {
        cerr << "Помилка: запис у файл-призначення не виконано." << endl;
        input.close();
        output.close();
        return Failure;
    }

    input.close();
    output.close();
    return Success;
}

int main() 
{
    char filename1[256];
    char content[256];

    cout << "Введіть ім'я файла для запису: ";
    cin.getline(filename1, 256);
    cout << "Введіть текст для запису у файл: ";
    cin.getline(content, 256);

    if (write_to_file(filename1, content) == Success) 
    {
        cout << "Дані успішно записані у файл \"" << filename1 << "\"." << endl;
    } 
    else 
    {
        cout << "Помилка запису у файл \"" << filename1 << "\"." << endl;
    }

    char file_from[256], file_to[256];

    cout << "Введіть ім'я файла-джерела для копіювання: ";
    cin.getline(file_from, 256);
    cout << "Введіть ім'я файла-призначення для копіювання: ";
    cin.getline(file_to, 256);

    if (copy_file(file_from, file_to) == Success) 
    {
        cout << "Файл \"" << file_from << "\" успішно скопійовано до \"" << file_to << "\"." << endl;
    } 
    else 
    {
        cout << "Помилка копіювання файла \"" << file_from << "\"." << endl;
    }

    return 0;
}
