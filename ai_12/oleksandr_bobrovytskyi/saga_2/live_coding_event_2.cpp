#include<iostream>
#include<fstream>
#include<string>
#include <sstream> 

using namespace std;

double GetTarifs(string s)
{
    ifstream file1;
    string value;
    double tarif;

    if(s == "meter")
    {
        file1.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/price_per_meter.txt");
        file1 >> tarif;
        file1.close();
    }
    else if(s == "miles_US")
    {
        file1.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/price_per_mile.txt");
        file1 >> tarif;
        file1.close();
    }
    else if(s == "miles")
    {
        file1.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/price_per_mile_us.txt");
        file1 >> tarif;
        file1.close();
    }

    return tarif;
}

string GetIdentificator(string Name)
{
    string ID;
    int code;
    char temp;

    for(int i = 0; i < Name.length(); i++)
    {
        for(int j = i+1; j < Name.length(); j++)
        {
            if(Name[i] > Name[j])
            {
                temp = Name[i];
                Name[i] = Name[j];
                Name[j] = temp;
            }
        }  
    }

    for(int i = 0; i < Name.length(); i++)
    {
        code = Name[i];
        ID.push_back(to_string(code));
    }

    return ID;
}

void StoreInfo(int ID, double distance)
{
    ofstream file;
    file.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/collected_distance.txt");

    file << ID << endl << distance;

    file.close();
}

double CheckForDiscount(int ID)
{
    double value;
    int FileID;
    ifstream file;
    file.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/collected_distance.txt");

    file >> FileID;
    
    if(ID == FileID)
    {   
        file >> value;
        return value;
    }
    return 0.0;
}

int main()
{
    int meter, miles_US, miles;
    string UserName, units, convertBonus;
    double distance, tarif, DiscountDIstance;
    int ID;

    cout << "Enter your name" << endl;
    cin >> UserName;

    cout << "Enter the distance to the destination" << endl;
    cin >> distance;

    cout << "Choose meter/miles_US/miles" << endl;
    cin >> units;

    if(units == "meter")
    {
        distance /= 1000;
    }
    else if(units == "miles")
    {
        distance /= 1609.344;
    }
    else if(units == "miles_US")
    {
        distance /= 1609.347;
    }

    tarif = GetTarifs(units);

    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;

    ID = GetIdentificator(UserName);

    StoreInfo(ID, distance);

    if(convertBonus == "y")
    {
        DiscountDIstance = CheckForDiscount(ID);
    }

    return 0;
}