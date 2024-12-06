#include <iostream>
#include <fstream>

using namespace std;

bool copyFile(const char *sourceFile, const char *targetFile) {
    ifstream source(sourceFile, ios::binary); 
    if (!source) {
        cout << "Не вдалося відкрити вихідний файл: " << sourceFile << endl;
        return false;
    }

    ofstream target(targetFile, ios::binary); 
    if (!target) {
        cout << "Не вдалося створити або відкрити файл для запису: " << targetFile << endl;
        return false;
    }

    target << source.rdbuf(); 

    if (target.fail()) {
        cout << "Помилка під час запису у файл: " << targetFile << endl;
        return false;
    }

    cout << "Файл успішно скопійовано." << endl;
    return true;
}

int main() {
    const char *sourceFile = "source.txt"; 
    const char *targetFile = "destination.txt"; 

    if (!copyFile(sourceFile, targetFile)) {
        cout << "Копіювання файлу не вдалося." << endl;
    }

    return 0;
}
