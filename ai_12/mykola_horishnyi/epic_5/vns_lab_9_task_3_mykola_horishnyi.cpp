#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ofstream fileF1("F1.txt");
    if (!fileF1) {
        cerr << "Error for opening file F1.txt " << endl;
        return 1;
    }


    fileF1 << "Bob" << endl;
    fileF1 << "Mike " << endl;
    fileF1 << "Maus" << endl;
    fileF1 << "Rose " << endl;
    fileF1 << "Diana " << endl;
    fileF1 << "Viki " << endl;
    fileF1 << "Ben " << endl;
    fileF1 << "Michael " << endl;
    fileF1 << "Stensy " << endl;
    fileF1 << "Amelia " << endl;
    fileF1.close();


    ifstream fileF1Read("F1.txt");
    ofstream fileF2("F2.txt");
    if (!fileF1Read || !fileF2)
    {
        cerr << "Error for opening file" << endl;
        return 1;
    }

    string line;
    while (getline(fileF1Read, line))
    {

        if (!line.empty() && line[0] == 'B')
        {
            fileF2 << line << endl;
        }
    }
    fileF1Read.close();
    fileF2.close();


    ifstream fileF2Read("F2.txt");
    int wordCount = 0;
    string word;
    while (fileF2Read >> word)
    {
        wordCount++;
    }
    fileF2Read.close();

    cout << "Amount of similar words in  F2: " << wordCount << endl;

    return 0;
}






