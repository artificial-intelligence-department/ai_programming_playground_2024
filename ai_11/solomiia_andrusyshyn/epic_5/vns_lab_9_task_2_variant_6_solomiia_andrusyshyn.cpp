#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void createFileF1(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Помилка відкриття файлу для запису!" << endl;
        return;
    }
    file << "Це перший рядок.\n";
    file << "Другий рядок містить більше тексту.\n";
    file << "Третій рядок також є.\n";
    file << "Четвертий рядок тестового файлу.\n";
    file << "П'ятий рядок тут.\n";
    file << "Шостий рядок для перевірки.\n";
    file << "Сьомий рядок.\n";
    file << "Восьмий рядок.\n";
    file << "Дев'ятий рядок тут.\n";
    file << "Десятий рядок для файлу F1.\n";
    file.close();
}

void copyLines(const string& fileF1, const string& fileF2, int N, int K) {
    ifstream inFile(fileF1);
    ofstream outFile(fileF2);

    if (!inFile || !outFile) {
        cout << "Помилка відкриття файлів для копіювання!" << endl;
        return;
    }

    string line;
    int lineNumber = 0;

    while (getline(inFile, line)) {
        ++lineNumber;
        if (lineNumber >= N && lineNumber <= K) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();
}

int countConsonants(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Помилка відкриття файлу для підрахунку!" << endl;
        return 0;
    }

    int consonantCount = 0;
    string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯaeiouyAEIOUY";
    char ch;

    while (file.get(ch)) {
        if (isalpha(ch) && vowels.find(ch) == string::npos) {
            ++consonantCount;
        }
    }

    file.close();
    return consonantCount;
}

int main() {
    string fileF1 = "F1.txt";
    string fileF2 = "F2.txt";

    createFileF1(fileF1);
    cout << "Файл F1 створено та заповнено.\n";

    int N, K;
    cout << "Введіть N (початковий номер рядка): ";
    cin >> N;
    cout << "Введіть K (кінцевий номер рядка): ";
    cin >> K;

    copyLines(fileF1, fileF2, N, K);
    cout << "Рядки з " << N << " до " << K << " скопійовано у файл F2.\n";

    int consonants = countConsonants(fileF2);
    cout << "Кількість приголосних букв у файлі F2: " << consonants << endl;

    return 0;
}
