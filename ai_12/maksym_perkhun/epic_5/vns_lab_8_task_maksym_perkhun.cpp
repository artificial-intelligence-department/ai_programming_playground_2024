#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;
struct sportTeam{
    char teamName[20];
    char city[20];
    int playerQ;
    int pointQ;
};

void addDataInFile(const char* fileName){
    sportTeam arr[]{
        {"RealMadrid", "Madrid", 15, 32},
        {"Barcelona", "Barcelona", 18, 19},
        {"Dynamo Kiev", "Kiev", 11, 33},
        {"Karpaty", "Lviv", 16, 39},
        {"Vorskla", "Poltava", 15, 14}
    };
    FILE* fileStream;
    fileStream = fopen(fileName, "wb");
    if (fileStream == nullptr){
        cerr << "Не вдалося відкрити файл";
        exit(0);
    }
    for (size_t i = 0; i < 5; i++)
    {
        int written = fwrite(&arr[i], sizeof(sportTeam), 1, fileStream);
        if (written != 1){
            cerr << "Не вдалось записати дані";
            exit(0); //?
    }
    }
    fclose(fileStream);
}

void pirntDataFromFile(const char* fileName){
    FILE* fileStream;
    fileStream = fopen(fileName, "rb");
    if (fileStream == nullptr){
        cerr << "Не вдалося відкрити файл";
        exit(0);
    }
    sportTeam temp;
    while(fread(&temp, sizeof(sportTeam), 1, fileStream) == 1){
        cout << "Назва команди: " << temp.teamName << endl;
        cout << "Місто: " << temp.city << endl;
        cout << "Кількість гравців: " << temp.playerQ << endl;
        cout << "Кількість очок: " << temp.pointQ << endl << endl;
    }
    fclose(fileStream);
}

void deleteElemfromFile(const char* fileName){
    FILE* fileStream;
    fileStream = fopen(fileName, "rb");
    if (fileStream == nullptr){
        cerr << "Не вдалося відкрити файл";
        exit(0);
    }
    vector <sportTeam> teams;
    sportTeam temp;
    int minPoint;
    cout << "Введіть мінімальну кількість очок: ";
    cin >> minPoint;
    cout << endl;
    while(fread(&temp, sizeof(sportTeam), 1, fileStream) == 1){
        if(temp.pointQ >= minPoint){
            teams.push_back(temp);
        }
    }
    fclose(fileStream);
    fileStream = fopen(fileName, "wb");
    if (fileStream == nullptr){
        cerr << "Не вдалося відкрити файл для запису";
        exit(0);
    }
    for(int i = 0; i < teams.size(); i++){
        fwrite(&teams[i], sizeof(sportTeam), 1, fileStream);
    }
    fclose(fileStream);
}

void addElemToFile(const char* fileName){
    FILE* fileStream;
    fileStream = fopen(fileName, "rb");
    if(fileStream == nullptr){
        cerr << "Не вдається відкрити файл для зчитування";
        exit(0);
    }
    vector<sportTeam> newTeams{
        {"Shakhtar", "Donetsk", 11, 35},
        {"Chornomorets", "Odesa", 20, 9}
    };
    vector <sportTeam> teams = newTeams;
    sportTeam temp; 
    while(fread(&temp, sizeof(sportTeam), 1, fileStream) == 1){
        teams.push_back(temp);
    }
    fclose(fileStream);
    fileStream = fopen(fileName, "wb");
    if (fileStream == nullptr){
        cerr << "Не вдалося відкрити файл";
        exit(0);
    }
    for (size_t i = 0; i < teams.size(); i++)
    {
        fwrite(&teams[i], sizeof(sportTeam), 1, fileStream);
    }
    fclose(fileStream);
}

int main(){
    const char* fileName = "lab8.bin";
    addDataInFile(fileName);
    pirntDataFromFile(fileName);
    deleteElemfromFile(fileName);
    addElemToFile(fileName);
    cout << "Елементи після операцій: " << endl << endl;
    pirntDataFromFile(fileName);
    return 0;
}