#include<bits/stdc++.h>

using namespace std;

enum FileOpResult{Success, Failure};

FileOpResult write_to_file(const char *name, char *content)
{
    ifstream fin;

    string line;

    string StringContent(content);

    fin.open(name);

    if(!fin.is_open())
    {
        cerr << "Error: unable to open the file";
        return Failure;
    }
    
    if(getline(fin, line))
    {
        if(line != StringContent)
        {
            cerr << "Error: input is not equal to file content";
            return Failure;
        }
    }
    else
    {
        cerr << "Error: file is clear";
        return Failure;
    }

    fin.close();

    return Success;
}

FileOpResult copy_file(const char *file_from, const char *file_to)
{
    ofstream fto;
    ifstream ffrom;
    
    vector<string> lines_from;
    vector<string> lines_to;

    string line;

    fto.open(file_to);
    ffrom.open(file_from);
    if(!fto.is_open())
    {
        cerr << "Error: unable to open the file 'to'" << endl;
        return Failure;
    }

    if(!ffrom.is_open())
    {
        cerr << "Error: unable to open the file 'from'" << endl;
        return Failure;
    } 

    while(getline(ffrom, line))
    {
        fto << line;
    }

    fto.close();
    ffrom.close();

    ifstream ftoCheck;
    ifstream ffromCheck;

    ftoCheck.open(file_to);
    ffromCheck.open(file_from);

    while(getline(ffromCheck, line))
    {
        lines_from.push_back(line);
    }

    while(getline(ftoCheck, line))
    {
        lines_to.push_back(line);
    }

    if(lines_from.size() == 0)
    {
        cerr << "Error: file 'from' is clear" << endl;
        return Failure;
    }

    if(lines_to.size() == 0)
    {
        cerr << "Error: file 'to' is clear" << endl;
        return Failure;
    }

    for(int i = 0; i < lines_from.size(); i++)
    {
        if(lines_from[i] != lines_to[i])
        {
            cerr << "Error: contents of the two files are not equal" << endl;
            return Failure;
        }
    }

    ftoCheck.close();
    ffromCheck.close();

    return Success;
}

int main()
{   
    ofstream fout;

    const char *FileName1 = "C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/epic_5/file_from.txt";
    const char *FileName2 = "C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/epic_5/file_to.txt";

    char content[256];

    fout.open(FileName1);

    if(!fout.is_open())
    {
        cout << Failure << endl;
        cerr << "Error: unable to open the file";
        return 1;
    } 

    cin.getline(content, 256);

    fout << content;

    fout.close();

    cout << "Execution status of the task 1 : " << write_to_file(FileName1, content) << endl;
    cout << "Execution status of the task 2 : " << copy_file(FileName1, FileName2);

    return 0;
}