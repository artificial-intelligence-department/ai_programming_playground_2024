#include <iostream>
#include <fstream>
#include <string>
#include <cctype>  // функції для роботи з символами(перевірки їх типу (літера, цифрa) та для зміни регістру букв)

using namespace std;

// Функція для підрахунку голосних літер в рядку
int countVowels(const string& line) {
    int count = 0;
    for (char c : line) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// Функція для створення текстового файлу F1 з кількома рядками
void createFileF1(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file << "This is the first line." << endl;
    file << "Another line is here." << endl;
    file << "Some random text to count vowels." << endl;
    file << "The quick brown fox jumps over the lazy dog." << endl;
    file << "This line has more vowels than the others." << endl;
    file << "Short one." << endl;
    file << "Another example line with vowels." << endl;
    file << "How many vowels are in this one?" << endl;
    file << "Line with the highest vowels number." << endl;
    file << "Just another line with vowels." << endl;

    file.close();
}

// Функція для копіювання всіх рядків з файлу F1 у файл F2, за винятком рядка з найбільшими голосними
void copyExcludingMaxVowelsLine(const string& filenameF1, const string& filenameF2) {
    ifstream fileF1(filenameF1);
    ofstream fileF2(filenameF2);

    if (!fileF1 || !fileF2) {
        cerr << "Error opening files!" << endl;
        return;
    }

    string line;
    int maxVowels = -1;
    int lineNum = 0;
    int maxVowelLineNum = 0;
    string lines[100];  // Масив для збереження всіх рядків

    // Підрахунок голосних та збереження рядків
    while (getline(fileF1, line)) {
        int vowels = countVowels(line);
        lineNum++;

		if (vowels > maxVowels) {  // Пошук рядка з найбільшими голосними
            maxVowels = vowels;
            maxVowelLineNum = lineNum;
        }

        lines[lineNum - 1] = line;  // Збереження рядка
    }

    // Копіювання всіх рядків, крім рядка з найбільшими голосними
    for (int i = 0; i < lineNum; i++) {
        if (i + 1 != maxVowelLineNum) {  // Пропускаємо рядок з найбільшими голосними
            fileF2 << lines[i] << endl;
        }
    }

    cout << "The line with the most vowels is number: " << maxVowelLineNum << endl;

    fileF1.close();
    fileF2.close();
}

int main() {
    const string filenameF1 = "F1.txt";
    const string filenameF2 = "F2.txt";

    // Створення файлу F1
    createFileF1(filenameF1);

    // Копіювання з F1 в F2, пропускаючи рядок з найбільшими голосними
    copyExcludingMaxVowelsLine(filenameF1, filenameF2);

    return 0;
}
