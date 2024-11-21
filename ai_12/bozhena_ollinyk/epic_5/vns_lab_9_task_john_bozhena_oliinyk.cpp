#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int lastWordLength(const string &line)
{
    int length = 0;
    string::size_type i = line.size();

    while (i > 0 && isspace(line[i - 1]))
    {
        i--;
    }

    while (i > 0 && !isspace(line[i - 1]))
    {
        length++;
        i--;
    }

    return length;
}

int main()
{
    ofstream f1("F1.txt");
    if (f1.is_open())
    {
        for (int i = 1; i < 11; i++)
        {
            string line;
            cout << "Input line № " << i << " : ";
            getline(cin, line);
            f1 << line << "\n";
        }
        f1.close();
    }

    ifstream inputFile("F1.txt");
    ofstream outputFile("F2.txt");
    string line;
    if (inputFile.is_open() && outputFile.is_open())
    {
        int lineCount = 0;
        while (getline(inputFile, line))
        {
            lineCount++;
            if (lineCount >= 4)
            {
                outputFile << line << endl;
            }
        }

        cout << "Copied successfully!" << endl;

        inputFile.close();
        outputFile.close();
    }

    ifstream f2("F2.txt");
    string lastLine;
    if (f2.is_open())
    {
        while (getline(f2, line))
        {
            lastLine = line;
        }
        f2.close();
    }

    int lastWord = lastWordLength(lastLine);
    cout << "Number of symbols in the last word of F2: " << lastWord << endl;

    if (remove("F1.txt") == 0 && remove("F2.txt") == 0)
    {
        cout << "Files \"F1.txt\" and \"F2.txt\" are removed successfully." << endl;
    }
    else
    {
        cout << "Couldn't delete files \"F1.txt\" and/or \"F2.txt\"." << endl;
    }

    return 0;
}
