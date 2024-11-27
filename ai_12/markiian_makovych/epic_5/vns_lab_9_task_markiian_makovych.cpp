#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    ifstream readFile("test.txt");
    fstream writeFile("out.txt", ios::in | ios::out | ios::trunc);

    if (readFile.is_open() && writeFile.is_open())
    {
        string line;
        while (getline(readFile, line))
        {
            istringstream iss(line);
            string firstWord, checkWord, tempWord;
            if (iss >> firstWord)
                tempWord = firstWord;

            bool isInLine = false;
            while (iss >> firstWord)
            {
                if (firstWord == tempWord)
                {
                    isInLine = true;
                }
            }
            if (!isInLine)
            {
                writeFile << line << endl;
            }
        }
    }
    readFile.close();

    writeFile.seekg(0, ios::beg);
    string checkLine;
    int count = 0;
    while (getline(writeFile, checkLine))
    {

        for (char a : checkLine)
        {
            if (a == ' ')
                continue;
            if (a != 'a' || a != 'e' || a != 'u' || a != 'i' || a != 'y' || a != 'o')
                count++;
        }
        break;
    }

    writeFile.seekp(0, ios::end); // Починаєм запис з кінця файлу
    writeFile << "Num of consonant letters: " << to_string(count) << endl;
    writeFile.close();

    return 0;
}