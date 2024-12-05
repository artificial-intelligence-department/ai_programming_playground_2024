#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_LINES = 100;
const int MAX_LENGTH = 255;

int countVowels(const char* line) 
{
    const char* vowels = "AEIOUaeiou";
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++) 
    {
        if (strchr(vowels, line[i]) != nullptr) 
        {
            count++;
        }
    }
    return count;
}

int main() 
{
    const char* file1 = "F1.txt"; 
    const char* file2 = "F2.txt"; 

    ofstream outFile(file1);
    if (!outFile) 
    {
        cerr << "Помилка відкриття файлу " << file1 << " для запису." << endl;
        return 1;
    }

    const char* lines[MAX_LINES] = 
    {
        "This is the first line.",
        "Here is another line.",
        "The quick brown fox jumps over the lazy dog.",
        "A simple example of a text file.",
        "I like to code in C++.",
        "This is a great day to learn programming.",
        "Practice makes perfect.",
        "Vowels are very important in words.",
        "Happy coding to everyone!",
        "This line has the most vowels."
    };

    int totalLines = 10; 
    for (int i = 0; i < totalLines; i++) 
    {
        outFile << lines[i] << endl;
    }
    outFile.close();

    ifstream inFile(file1);
    if (!inFile) 
    {
        cerr << "Помилка відкриття файлу " << file1 << " для читання." << endl;
        return 1;
    }

    char allLines[MAX_LINES][MAX_LENGTH];
    int maxVowels = 0;
    int maxVowelLineIndex = -1;
    int lineIndex = 0;

    while (inFile.getline(allLines[lineIndex], MAX_LENGTH)) 
    {
        int vowelCount = countVowels(allLines[lineIndex]);
        if (vowelCount > maxVowels) 
        {
            maxVowels = vowelCount;
            maxVowelLineIndex = lineIndex;
        }
        lineIndex++;
    }
    inFile.close();
    totalLines = lineIndex;

    ofstream outFile2(file2);
    if (!outFile2) 
    {
        cerr << "Помилка відкриття файлу " << file2 << " для запису." << endl;
        return 1;
    }

    for (int i = 0; i < totalLines; i++) 
    {
        if (i != maxVowelLineIndex) 
        {
            outFile2 << allLines[i] << endl;
        }
    }
    outFile2.close();

    cout << "Рядок з найбільшою кількістю голосних букв: " << endl;
    cout << "Номер рядка: " << maxVowelLineIndex + 1 << endl;
    cout << "Текст рядка: " << allLines[maxVowelLineIndex] << endl;

    return 0;
}
