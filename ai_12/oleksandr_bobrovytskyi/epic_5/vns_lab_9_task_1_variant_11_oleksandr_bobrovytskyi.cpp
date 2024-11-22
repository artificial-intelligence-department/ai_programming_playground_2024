#include <bits/stdc++.h>

using namespace std;

vector<string> StringSpliter(string &line)
{
    stringstream s(line);
    string word;
    vector<string> SeparatedString;

    while (s >> word) {
        SeparatedString.push_back(word);
    }

    return SeparatedString;
}

void OutputOfAFile(string &FileName)
{   
    string line;
    ifstream fout;

    fout.open(FileName);

    if(!fout)
    {
        cerr << "Error: unable to open the file";
        return;
    }

    while(fout)
    {
        getline(fout, line);

        cout << line << endl; 
    }

    fout.close();
}

void CopyFileInfo(string &FileName1, string &FileName2)
{
    string line;
    ifstream fin;
    ofstream fout;
    fin.open(FileName1);
    fout.open(FileName2);

    vector<string> SeparatedString;
    string ShortestWord;

    if (!fin.is_open() || !fout.is_open) {
        cerr << "Error opening files!" << endl;
        return;
    }

    while(getline(fin, line))
    {
        SeparatedString = StringSpliter(line);

        if(!SeparatedString.empty())
        {
            ShortestWord = SeparatedString[0];

            for(int i = 0; i < SeparatedString.size(); i++)
            {
                if(SeparatedString[i].length() < ShortestWord.length())
                {
                ShortestWord = SeparatedString[i];
                }
            }
        }
    }

    int count = 0;
    int SkippedLine = -1;

    fin.clear();
    fin.seekg(0, ios::beg);

    while(fin)
    {
        getline(fin, line);
        SeparatedString = StringSpliter(line);
        count++;

        for(int i = 0; i < SeparatedString.size(); i++)
        {
            if(SeparatedString[i] == ShortestWord)
            {
                SkippedLine = count;
            }
        }
    }

    count = 0;

    fin.clear();
    fin.seekg(0, ios::beg);

    while(getline(fin, line))
    {   
        count++;
        if(count != SkippedLine)
        {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
}

int main()
{   
    ofstream fout;
    string line;

    string FileName1 = "C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/epic_5/F1.txt";
    string FileName2 = "C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/epic_5/F2.txt";

    fout.open(FileName1);

    cout << "Enter the text using 'Enter' between each string, or type in -1 to exit" << endl; 

    while(fout)
    {
        getline(cin, line);
        if(line == "-1")
        {
            break;
        }
        fout << line << endl;
    }

    CopyFileInfo(FileName1, FileName2);

    cout << "Text from the first file: " << endl;
    OutputOfAFile(FileName1);

    cout << "Text from the second file: " << endl;
    OutputOfAFile(FileName2);

    fout.close();

    return 0;
}