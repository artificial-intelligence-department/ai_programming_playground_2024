// 3 частина:
// - Щоб вміти записувати в файл не достатньо знати базові функції (але відкриття, закриття, запис, читатння терба знати), ще треба окремо розібратись про формати запису даних у файл:
// - більше прочитати про текстові формати і в них попрактикуватись:
// - Plain Text (читати і попрактикуватись)
// - Comma-Separated Values (читати і попрактикуватись)
// - JavaScript Object Notation (для душі - поки не розбиратись)
// - Extensible Markup Language (для душі - поки не розбиратись)
// - Yet Another Markup Language (для душі - поки не розбиратись)
// - Двійкові формати
// - багато різних покищо не рухайте
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void WriteToFile(string filepath)
{
    ofstream myFile(filepath);

    cout << "Введіть текст, який хочете записати у файл: " << endl;
    string line;
    cin.ignore();
    getline(cin, line); 
    myFile << line << endl;

    myFile.close();
}


void ReadFromFile(string filepath)
{
    ifstream myFile(filepath);

    cout << "Дані з файлу: " << endl;
    string line;
    while (getline(myFile, line)) 
    {
        cout << "\"" << line << "\"" << endl;
    }

    myFile.close();
}

int main()
{
    string filepath = "text.txt";

    cout << "=============== FILES ===============" << endl;
    int choise;
    while (true)
    {
        cout << "Зробіть вибір:\n1) Записати дані у файл\n2) Вивести дані з файлу\n3) Вийти\nВибір: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            WriteToFile(filepath);
            break;
        case 2:
            ReadFromFile(filepath);
            break;
        case 3:
            return false;
            break;
        default:
            cout << "Непраивльний вибір!" << endl;
            break;
        }

    }
    

    return 0;
}