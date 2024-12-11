#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream file("file.txt", ios::in | ios::out | ios::trunc);

    if (!file.is_open())
    {
        cerr << "Failed to open the file.\n";
        return 1;
    }

    file << "Hello, World!";

    file.seekg(0);

    string line;
    getline(file, line);

    cout << "Read from file: " << line << "\n";

    file.seekp(0, ios::end);
    file << "Appending this line.\n";

    file.close();

    
}