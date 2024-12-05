#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct MDisc 
{
    char title[50];
    char author[50];
    float duration; 
    float price;    
};

void crFile(const char* filename) 
{
    ofstream outFile(filename, ios::binary);
    if (!outFile) 
    {
        cerr << "Помилка при відкритті файлу для запису!" << endl;
        return;
    }

    int n;
    cout << "Введіть кількість дисків: ";
    cin >> n;

    for (int i = 0; i < n; ++i) 
    {
        MDisc disc;
        cout << "Введіть назву диска: ";
        cin.ignore();
        cin.getline(disc.title, 50);
        cout << "Введіть автора диска: ";
        cin.getline(disc.author, 50);
        cout << "Введіть тривалість диска: ";
        cin >> disc.duration;
        cout << "Введіть ціну диска: ";
        cin >> disc.price;

        outFile.write(reinterpret_cast<char*>(&disc), sizeof(MDisc));
    }
    outFile.close();
}

void printF(const char* filename) 
{
    ifstream inFile(filename, ios::binary);
    if (!inFile) 
    {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    MDisc disc;
    cout << "Вміст файлу:" << endl;
    while (inFile.read(reinterpret_cast<char*>(&disc), sizeof(MDisc))) 
    {
        cout << "Назва: " << disc.title << ", Автор: " << disc.author << ", Тривалість: " << disc.duration << ", Ціна: " << disc.price << endl;
    }
    inFile.close();
}

void deleteD(const char* filename, float duration) 
{
    ifstream inFile(filename, ios::binary);
    if (!inFile) 
    {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    ofstream tempFile("temp.bin", ios::binary);
    if (!tempFile) 
    {
        cerr << "Помилка при створенні тимчасового файлу!" << endl;
        return;
    }

    MDisc disc;
    bool deleted = false;

    while (inFile.read(reinterpret_cast<char*>(&disc), sizeof(MDisc))) 
    {
        if (!deleted && disc.duration == duration) 
        {
            deleted = true;
            continue; 
        }
        tempFile.write(reinterpret_cast<char*>(&disc), sizeof(MDisc));
    }

    inFile.close();
    tempFile.close();

    remove(filename);            
    rename("temp.bin", filename); 

    if (deleted) 
    {
        cout << "Елемент із тривалістю " << duration << " видалено." << endl;
    } 
    else 
    {
        cout << "Елемент із тривалістю " << duration << " не знайдено." << endl;
    }
}

void addE(const char* filename, int index) 
{
    ifstream inFile(filename, ios::binary);
    if (!inFile) 
    {
        cerr << "Помилка при відкритті файлу для читання!" << endl;
        return;
    }

    ofstream tempFile("temp.bin", ios::binary);
    if (!tempFile) 
    {
        cerr << "Помилка при створенні тимчасового файлу!" << endl;
        return;
    }

    MDisc disc;
    int cIndex = 0;

    while (inFile.read(reinterpret_cast<char*>(&disc), sizeof(MDisc))) 
    {
        tempFile.write(reinterpret_cast<char*>(&disc), sizeof(MDisc));
        if (cIndex == index) 
        {
            for (int i = 0; i < 2; ++i) 
            {
                MDisc newDisc;
                cout << "Введіть назву нового диска: ";
                cin.ignore();
                cin.getline(newDisc.title, 50);
                cout << "Введіть автора нового диска: ";
                cin.getline(newDisc.author, 50);
                cout << "Введіть тривалість нового диска: ";
                cin >> newDisc.duration;
                cout << "Введіть ціну нового диска: ";
                cin >> newDisc.price;

                tempFile.write(reinterpret_cast<char*>(&newDisc), sizeof(MDisc));
            }
        }
        ++cIndex;
    }

    inFile.close();
    tempFile.close();

    remove(filename);            
    rename("temp.bin", filename); 

    cout << "Два нових елементи додано після індексу " << index << "." << endl;
}

int main() 
{
    const char* filename = "music_discs.bin";

    crFile(filename);
    printF(filename);

    float durationD;
    cout << "Введіть тривалість для видалення елемента: ";
    cin >> durationD;
    deleteD(filename, durationD);
    printF(filename);

    int indexE;
    cout << "Введіть номер індексу, після якого додати два елементи: ";
    cin >> indexE;
    addE(filename, indexE);
    printF(filename);

    return 0;
}
