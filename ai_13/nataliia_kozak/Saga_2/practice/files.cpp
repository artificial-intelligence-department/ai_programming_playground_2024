#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct Human
{
    string name;
    int age;
    char grade;
};
void write_in_csv()
{
    Human list[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> list[i].name >> list[i].age >> list[i].grade;
    }
    fstream MyFile("MyFile.txt", ios::out | ios::trunc);
    MyFile << "Name," << "Age," << "Grade" << endl;
    for (int i = 0; i < 5; i++)
    {
        MyFile << list[i].name << ',' << list[i].age << ',' << list[i].grade << endl;
    }

    MyFile.close();
}
void read()
{
    fstream MyFile("MyFile.txt", ios::in);
    string line, word;
    Human list[5];
    getline(MyFile, line);
    cout << endl;
    for (int i = 0; i < 5; i++)
    {
        getline(MyFile, line, '\n');
        stringstream ss(line);
        for(int i = 0; i < 3; i++){
            getline(ss, word, ',');
            cout << word << ' ';
        }
        cout << endl;
    }
}
int main()
{
    write_in_csv();
    read();
    return 0;
}