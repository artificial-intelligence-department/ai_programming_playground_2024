#include <fstream>
#include <iostream>
#include <string>
#include <limits>
using namespace std;
enum FileOpResult
{
    Success = 0,
    Failure = 1
};
FileOpResult write_to_file(char *name, char *content)
{
    ofstream my_file(name);
    if (!my_file)
    {
        return Failure;
    }

    my_file << content;
    my_file.close();

    if (my_file.fail())
    {
        return Failure;
    }
    return Success;
}

FileOpResult copy_file(char *file_from, char *file_to)
{
    ifstream f_file(file_from);
    if (!f_file)
    {
        return Failure;
    }

    ofstream t_file(file_to);
    if (!t_file)
    {
        return Failure;
    }
    string line;
    getline(f_file, line);
    t_file << line;

    t_file.close();
    f_file.close();
    return Success;
}
int main()
{
    char name[20], content[100];
    cout << endl;
    cin >> name;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(content, 100);

    if (write_to_file(name, content) == Success)
    {
        cout << "hooray" << endl;
    }
    else
    {
        cout << "oops, something went wrong" << endl;
    }

    char name2[] = "second_file";
    if (copy_file(name, name2) == Failure)
    {
        cout << "oops, something went wrong" << endl;
    }
    else
    {
        cout << "hooray" << endl;
    }

    return 0;
}