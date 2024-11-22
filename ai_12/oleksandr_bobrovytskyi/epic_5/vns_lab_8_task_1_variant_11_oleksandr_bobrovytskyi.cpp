#include <bits\stdc++.h>

using namespace std;

struct Videotape{
    string name;
    string director;
    double RunnningTime;
    double price; 

    void input()
    {
        cout << "Enter the new name of the videotape" << endl;
        getline(cin >> ws, name);

        cout << "Enter the new name of the director" << endl;
        getline(cin, director);

        cout << "Enter the new running time of the film" << endl;
        cin >> RunnningTime;

        cout << "Enter the new price of the videotape" << endl;
        cin >> price;
        
    }
};

void WriteInFile(string &FileName, vector<Videotape> &tapes)
{
    ofstream fin;

    fin.open(FileName, ios::binary);

    if(!fin)
    {
        cerr << "Error: unable to open the file";
        return;
    }

    for(int i = 0; i < tapes.size(); i++)
    {
        fin << tapes[i].name << endl << tapes[i].director << endl << tapes[i].RunnningTime << endl << tapes[i].price << endl << endl ;
    }

    fin.close();
}

void DeleteByPrice(string &FileName, vector<Videotape> &tapes, double MaxPrice)
{
    ofstream fdel;

    fdel.open(FileName, ios::binary | ios::trunc);

    if(!fdel)
    {
        cerr << "Error: unable to open the file";
        return;
    }

    for(int j = 0; j < tapes.size(); j++)
    {
        if(tapes[j].price > MaxPrice)
        {
            tapes.erase(tapes.begin() + j);
        }
    }

    for(int i = 0; i < tapes.size(); i++)
    {
        fdel << tapes[i].name << endl << tapes[i].director << endl << tapes[i].RunnningTime << endl << tapes[i].price << endl << endl ;
    }

    fdel.close();
}

void OutputOfAFile(string &FileName)
{   
    string line;
    ifstream fout;

    fout.open(FileName, ios::binary);

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

void AddToEnd(string &FileName, vector<Videotape> &tapes)
{
    ofstream fin;

    fin.open(FileName, ios::binary | ios::app);

    if(!fin)
    {
        cerr << "Error: unable to open the file";
        return;
    }

    for(int i = 0; i < tapes.size(); i++)
    {
        fin << endl << tapes[i].name << endl << tapes[i].director << endl << tapes[i].RunnningTime << endl << tapes[i].price << endl ;
    }

    fin.close();
}

int main()
{
    string FileName = "VideotapeList.bin";
    double MaxPrice = 0;

    vector<Videotape> InitialTapes = {
        {"Film1", "Director1", 150.0, 15.0},
        {"Film2", "Director2", 125.0, 20.0},
        {"Film3", "Director3", 90.0, 10.0},
        {"Film4", "Director4", 100.0, 25.0}
    };

    cout << "Enter the max price:" << endl;
    cin >> MaxPrice;

    WriteInFile(FileName, InitialTapes);

    OutputOfAFile(FileName);

    DeleteByPrice(FileName, InitialTapes, MaxPrice);

    vector<Videotape> NewTapes(3);
    cout << "Add 3 more videotapes " << endl;
    for(int i = 0; i < 3; i++)
    {
        NewTapes[i].input();
    }

    AddToEnd(FileName, NewTapes);

    cout << "New List of videotapes: " << endl;
    OutputOfAFile(FileName);

    return 0;
}