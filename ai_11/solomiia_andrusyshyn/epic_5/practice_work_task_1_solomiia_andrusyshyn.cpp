#include <iostream>
#include <fstream>

using namespace std;

enum OperationStatus { Ok, Error };

OperationStatus saveToFile(const char *fileName, const char *data) {
    ofstream outFile(fileName);
    
    if (!outFile.is_open()) {
        cerr << "Помилка: неможливо відкрити файл для запису." << endl;
        return Error;
    }

    outFile << data;

    if (outFile.fail()) {
        cerr << "Помилка: запис у файл не вдався." << endl;
        return Error;
    }

    outFile.close();
    if (outFile.fail()) {
        cerr << "Помилка: закриття файлу завершилося помилкою." << endl;
        return Error;
    }

    return Ok;
}

int main() {
    const char *fileName = "OutputFile.txt";
    char inputText[256];
    
    cout << "Введіть текст для запису у файл: ";
    cin.getline(inputText, 256);
    
    OperationStatus status = saveToFile(fileName, inputText);
    
    if (status == Ok) {
        cout << "Файл успішно записаний." << endl;
    } else {
        cout << "Не вдалося записати файл." << endl;
    }

    return 0;
}
