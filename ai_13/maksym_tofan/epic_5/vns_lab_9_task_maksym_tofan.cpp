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

    std::ofstream fileF1("F1.txt");
    for (const auto& line : linesF1) {
        fileF1 << line << std::endl;
    }
    fileF1.close();

   
    int N1 = 2, N2 = 6;  
    std::ifstream fileF1In("F1.txt");
    std::ofstream fileF2("F2.txt");

    std::string line;
    int lineNumber = 1;
    while (std::getline(fileF1In, line)) {
        if (lineNumber >= N1 && lineNumber <= N2 && !line.empty() && std::tolower(line[0]) == 'a') {
            fileF2 << line << std::endl;
        }
        lineNumber++;
    }
    fileF1In.close();
    fileF2.close();

    
    std::ifstream fileF2In("F2.txt");
    int maxConsonants = 0;
    int maxConsonantsLine = 0;
    int currentLineNumber = 1;

    while (std::getline(fileF2In, line)) {
        int consonantsCount = countConsonants(line);
        if (consonantsCount > maxConsonants) {
            maxConsonants = consonantsCount;
            maxConsonantsLine = currentLineNumber;
        }
        currentLineNumber++;
    }

    fileF2In.close();

    std::cout << "The line with the most consonants is line number " << maxConsonantsLine << std::endl;
    return 0;
}
