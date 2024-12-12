#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct inf
{
    string l;
    int value;
    char c;
};

void readCSV(string filename)
{
    ifstream file(filename);
    string line, data;
    while (getline(file, line))
    {
        stringstream ss(line);
        for (int i = 0; i < 3; i++)
        {
            getline(ss, data, ',');
            cout << data << " ";
        }
        cout << endl;
    }
    file.close();
}

void writeCSV(string filename, inf *list)
{
    ofstream file(filename);

    for (int i = 0; i < 4; i++)
    {
        file << list[i].l << ',' << list[i].value << ',' << list[i].c << endl;
    }
    file.close();
}

int main()
{
    inf list[4];
    for (int i = 0; i < 4; i++)
        cin >> list[i].l >> list[i].value >> list[i].c;

    writeCSV("fileCSV.txt", list);
    readCSV("fileCSV.txt");

    return 0;
}