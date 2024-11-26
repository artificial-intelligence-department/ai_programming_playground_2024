#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int countWordsInLine(const string& line) 
{
    int wordCount = 0;
    bool inWord = false;

    for (char c : line) 
    {
        if (isspace(c)) 
        {
            if (inWord) 
            {
                ++wordCount;
                inWord = false;
            }
        } 
        else 
        {
            inWord = true;
        }
    }

    if (inWord) 
    {
        ++wordCount; 
    }

    return wordCount;
}

int main() 
{
    ifstream fileF1("F1.txt");
    ofstream fileF2("F2.txt");

    if (!fileF1.is_open() || !fileF2.is_open()) 
    {
        cerr << "Помилка відкриття файлу!" << "\n";
        return 1;
    }

    int N1, N2;
    cout << "Введіть N1 та N2: ";
    cin >> N1 >> N2;

    string line;
    int lineNumber = 0;
    vector<string> linesToWrite;

    while (getline(fileF1, line)) 
    {
        ++lineNumber;

        if (lineNumber >= N1 && lineNumber <= N2 && !line.empty() && line[0] == 'A') 
        {
            linesToWrite.push_back(line);
        }

        if (lineNumber > N2 + 2) 
        {
            linesToWrite.push_back(line);
        }
    }

    for (const auto& l : linesToWrite) 
    {
        fileF2 << l << "\n";
    }

    fileF1.close();
    fileF2.close();

    if (!linesToWrite.empty()) 
    {
        const string& lastLine = linesToWrite.back();
        int wordCount = countWordsInLine(lastLine);
        cout << "Кількість слів в останньому рядку F2: " << wordCount << "\n";
    } 
    else 
    {
        cout << "Файл F2 порожній." << "\n";
    }

    return 0;
}
