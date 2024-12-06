#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <sstream>
#include <cctype>

bool hasDuplicateWords(const std::string& line) {
    std::set<std::string> words;
    std::istringstream stream(line);
    std::string word;
    while (stream >> word) {
        if (words.count(word)) {
            return true;
        }
        words.insert(word);
    }
    return false;
}

int countVowels(const std::string& line) {
    int count = 0;
    const std::string vowels = "AEIOUaeiouАЕіИОУЮЯаеиоуюя";
    for (size_t i = 0; i < line.size(); ++i) {
        if (vowels.find(line[i]) != std::string::npos) {
            ++count;
        }
    }
    return count;
}

void createFileF1(const char* filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Помилка при створенні файлу F1.\n";
        return;
    }

    outFile << "Це перший рядок файлу.\n";
    outFile << "Це другий рядок з повтором слово слово.\n";
    outFile << "Один раз використане слово.\n";
    outFile << "Ще один рядок без дублікатів.\n";
    outFile << "Це рядок, де дубль слово слово ще раз.\n";
    outFile << "Цей рядок унікальний.\n";
    outFile << "Це тестовий рядок.\n";
    outFile << "Слово слово тут є двічі.\n";
    outFile << "Це останній рядок з дублем дублем.\n";
    outFile << "Рядок без дублікатів.\n";

    outFile.close();
}

void copyDuplicateLines(const char* filenameF1, const char* filenameF2) {
    std::ifstream inFile(filenameF1);
    if (!inFile) {
        std::cerr << "Помилка при відкритті файлу F1 для читання.\n";
        return;
    }

    std::ofstream outFile(filenameF2);
    if (!outFile) {
        std::cerr << "Помилка при створенні файлу F2.\n";
        inFile.close();
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (hasDuplicateWords(line)) {
            outFile << line << '\n';
        }
    }

    inFile.close();
    outFile.close();
}

int countVowelsInLastLine(const char* filenameF2) {
    std::ifstream inFile(filenameF2);
    if (!inFile) {
        std::cerr << "Помилка при відкритті файлу F2 для читання.\n";
        return 0;
    }

    std::string line, lastLine;
    while (std::getline(inFile, line)) {
        lastLine = line;
    }

    inFile.close();

    return countVowels(lastLine);
}

int main() {
    const char* filenameF1 = "F1.txt";
    const char* filenameF2 = "F2.txt";

    // Створення файлу F1
    createFileF1(filenameF1);

    // Копіювання рядків з дубльованими словами у F2
    copyDuplicateLines(filenameF1, filenameF2);

    // Визначення кількості голосних в останньому рядку F2
    int vowelsCount = countVowelsInLastLine(filenameF2);

    std::cout << "Кількість голосних букв в останньому рядку файлу F2: " << vowelsCount << "\n";

    return 0;
}
