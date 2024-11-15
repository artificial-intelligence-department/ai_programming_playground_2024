#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum FileOpResult { Success, Failure };

FileOpResult write(const char *name, const char *content) {
    ofstream fout(name);
    if (!fout.is_open()) 
    {
        return Failure;
    }
    fout << content;
    if (!fout) 
    {
        return Failure;
    }
    fout.close();
    return Success;
}

int main() {
    string name1 = "file_from.txt";
    string content;

    cout << "Введіть інформацію, яка буде записана у файл:" << endl;
    getline(cin, content);

    FileOpResult result = write(name1.c_str(), content.c_str());
    if (result == Failure) 
    {
        cout << "Failure" << endl;
        return 1;
    }
    cout << "Success" << endl;

    return 0;
}
