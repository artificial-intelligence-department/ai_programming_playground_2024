#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cwctype>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>

bool twoIdentWords(const std::string &line);
int mostDigitWord(const std::string &line);

int main()
{
    std::ifstream inputFile("F1.txt");
    std::ofstream outputFile("F2.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        std::cerr << "error opening file" << '\n';
        return 1;
    }

    std::string line;
    while (getline(inputFile, line))
    {
        if (twoIdentWords(line))
        {
            outputFile << line << std::endl;
        }
        int wordIdx = mostDigitWord(line);
        if (wordIdx != -1)
        {
            std::cout << "in line: \"" << line << "\" index of word with most digits is: " << wordIdx << '\n';
        }
    }
    inputFile.close();
    outputFile.close();

    return 0;
}

bool twoIdentWords(const std::string &line)
{
    std::unordered_map<std::string, int> wordCount;
    std::istringstream iss(line);
    std::string word;

    while (iss >> word)
    {
        wordCount[word]++;
        if (wordCount[word] >= 2)
        {
            return 1;
        }
    }
    return 0;
}

int mostDigitWord(const std::string &line)
{
    std::istringstream iss(line);
    std::string word;
    int maxD = 0;
    int maxDIdx = -1;
    int idx = 0;
    while (iss >> word)
    {
        int count = std::count_if(word.begin(), word.end(), ::isdigit);
        if (count > maxD)
        {
            maxD = count;
            maxDIdx = idx;
        }
        idx++;
    }
    return maxDIdx;
}
