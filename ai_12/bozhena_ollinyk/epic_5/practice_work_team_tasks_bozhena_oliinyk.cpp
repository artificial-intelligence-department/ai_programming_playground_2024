#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

void writeToFile(const string &name, const string &content)
{
    ofstream file(name, ios::out);
    if (file.is_open())
    {
        file << content;
        file.close();
        cout << "Success in creating and opening file \""<< name << "\"" << endl;
    }
    else
    {
        cout << "Failure in creating or opening file \"" << name << "\"" << endl;
    }

    ifstream infile(name);
    if (infile.is_open())
    {
        string line;
        getline(infile, line);

        cout << line << endl;

        infile.close();
        cout << "Success in reading from file \"" << name << "\"" << endl;
    }
    else
    {
        cout << "Failure in reading from file \"" << name << "\"" <<endl;
    }
}

void copyFile (const string &file_from, const string &file_to){
    ifstream infile(file_from);
    ofstream outfile(file_to, ios::out);

    if (infile.is_open() && outfile.is_open())
    {
        string line;
        getline(infile, line);

        outfile << line;

        infile.close();
        cout << "Success in copying from \"" << file_from << "\" to \"" << file_to << "\"" << endl;
    }
    else
    {
        cout << "Failure in copying from \"" << file_from << "\" to \"" << file_to << "\"" << endl;
    }

}

int main()
{
    string filename;
    cout << "Input the name of file: ";
    cin >> filename;

    cin.ignore();

    string content;
    cout << "Input content of file: ";
    getline(cin, content); 

    string copyfilename;
    cout << "Input the name of file in which we`ll copy information: ";
    cin >> copyfilename;

    writeToFile(filename, content);
    copyFile(filename, copyfilename);

    if (remove(filename.c_str()) == 0 && remove(copyfilename.c_str()) == 0)
    {
        cout << "Files\"" << filename << "\" , \"" << copyfilename << "\" are removed" << endl;
    }
    else
    {
        cout << "Couldn`t delete files \"" << filename << "\" , \"" << copyfilename << "\"" << endl;
    }

    

    return 0;
}
