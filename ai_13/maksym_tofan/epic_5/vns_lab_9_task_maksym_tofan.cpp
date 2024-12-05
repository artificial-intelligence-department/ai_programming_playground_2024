#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

bool isConsonant(char c) {
    c = std::tolower(c);
    return (c >= 'a' && c <= 'z') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int countConsonants(const std::string& line) {
    int count = 0;
    for (char c : line) {
        if (isConsonant(c)) {
            count++;
        }
    }
    return count;
}

void writeBinaryFile(const std::vector<std::string>& lines, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    for (const auto& line : lines) {
        size_t length = line.size();
        file.write(reinterpret_cast<char*>(&length), sizeof(length));
        file.write(line.c_str(), length);
    }
    file.close();
}

void readBinaryFile(std::vector<std::string>& lines, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    while (file) {
        size_t length;
        file.read(reinterpret_cast<char*>(&length), sizeof(length));
        if (!file) break;

        char* buffer = new char[length + 1];
        file.read(buffer, length);
        buffer[length] = '\0';

        lines.push_back(std::string(buffer));
        delete[] buffer;
    }
    file.close();
}

int main() {
    std::vector<std::string> linesF1 = {
        "Apple is a fruit.",
        "Banana is yellow.",
        "Ants are small insects.",
        "Apricot is sweet.",
        "Aardvarks are nocturnal.",
        "Cats are cute animals.",
        "Anatomy is the study of the body.",
        "Aeroplanes fly in the sky.",
        "Balloon is colorful.",
        "Animal kingdom is diverse."
    };

    writeBinaryFile(linesF1, "F1.bin");

    std::vector<std::string> linesF1Read;
    readBinaryFile(linesF1Read, "F1.bin");

    int N1 = 2, N2 = 6;  
    std::ofstream fileF2("F2.bin", std::ios::binary);
    int lineNumber = 1;
    for (const auto& line : linesF1Read) {
        if (lineNumber >= N1 && lineNumber <= N2 && !line.empty() && std::tolower(line[0]) == 'a') {
            size_t length = line.size();
            fileF2.write(reinterpret_cast<char*>(&length), sizeof(length));
            fileF2.write(line.c_str(), length);
        }
        lineNumber++;
    }
    fileF2.close();

    std::vector<std::string> linesF2Read;
    readBinaryFile(linesF2Read, "F2.bin");

    int maxConsonants = 0;
    int maxConsonantsLine = 0;
    int currentLineNumber = 1;
    for (const auto& line : linesF2Read) {
        int consonantsCount = countConsonants(line);
        if (consonantsCount > maxConsonants) {
            maxConsonants = consonantsCount;
            maxConsonantsLine = currentLineNumber;
        }
        currentLineNumber++;
    }

    std::cout << "The line with the most consonants is line number " << maxConsonantsLine << std::endl;

    return 0;
}
