#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ifstream file1("F1.txt");
    ofstream file2("F2.txt");
    if (!file1)
    {
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }
    if (!file2)
    {
        cerr << "Error opening file for writting!" << endl;
        return 1;
    }

    string line;
    string biggestWord;
    int max = -1;
    while (getline(file1, line))
    {
        stringstream ss(line);
        std::string word;
        int wordCount = 0;

        while (ss >> word)
        {
            wordCount++;
        }

        if (wordCount == 1)
        {
            file2.write(line.c_str(), line.size());
            if (static_cast<int>(line.size()) > max)
            {
                biggestWord = line;
                max = line.size();
            }
            file2.put('\n');
        }
    }

    cout << "The biggest word in file2: " << biggestWord;
    file1.close();
    file2.close();

    return 0;
}