#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult copy(const char *file_from, const char *file_to) {
    ifstream fin(file_from);
    if (!fin.is_open()) 
    {
        return Failure;
    }
    ofstream fout(file_to);
    if (!fout.is_open()) 
    {
        return Failure;
    }
    string line;
    while (getline(fin, line)) 
    {
        fout << line << endl;
    }
    if (!fout) 
    {
        return Failure;
    }
    fin.close();
    fout.close();
    return Success;
}

int main() {
    string name1 = "file_from.txt";
    string name2 = "file_to.txt";

    FileOpResult result = copy(name1.c_str(), name2.c_str());
    if (result == Failure) 
    {
        cout << "Failure" << endl;
        return 1;
    }
    cout << "Success" << endl;

    return 0;
}