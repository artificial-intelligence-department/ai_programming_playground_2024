#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

bool isConsonant(char c) {
    c = std::tolower(c);
    return std::isalpha(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y';
}

int main() {
    const std::string file1 = "F1.txt";
    const std::string file2 = "F2.txt";
    int N1, N2;

    std::cout << "Введіть номер N1: ";
    std::cin >> N1;
    std::cout << "Введіть номер N2: ";
    std::cin >> N2;

    std::ofstream outFile(file1);
    if (!outFile) {
        std::cerr << "Помилка створення файлу F1!" << std::endl;
        return 1;
    }

    outFile << "Apple\n"
            << "Banana\n"
            << "Apricot\n"
            << "Orange\n"
            << "Avocado\n";
    outFile.close();

    std::ifstream inFile(file1);
    if (!inFile) {
        std::cerr << "Помилка відкриття файлу F1!" << std::endl;
        return 1;
    }

    std::ofstream outFile2(file2);
    if (!outFile2) {
        std::cerr << "Помилка створення файлу F2!" << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 0;
    std::vector<std::string> selectedLines;

    while (std::getline(inFile, line)) {
        ++lineNumber;
        if (lineNumber >= N1 && lineNumber <= N2 && !line.empty() && line[0] == 'A') {
            outFile2 << line << "\n";
            selectedLines.push_back(line);
        }
    }

    inFile.close();
    outFile2.close();

    int maxConsonants = 0;
    int maxLineIndex = -1;

    for (size_t i = 0; i < selectedLines.size(); ++i) {
        int consonantCount = 0;
        for (char c : selectedLines[i]) {
            if (isConsonant(c)) {
                ++consonantCount;
            }
        }
        if (consonantCount > maxConsonants) {
            maxConsonants = consonantCount;
            maxLineIndex = i + 1;
        }
    }

    if (maxLineIndex != -1) {
        std::cout << "Рядок з найбільшою кількістю приголосних у файлі F2: " << maxLineIndex << std::endl;
    } else {
        std::cout << "У файлі F2 немає рядків для аналізу." << std::endl;
    }

    return 0;
}
