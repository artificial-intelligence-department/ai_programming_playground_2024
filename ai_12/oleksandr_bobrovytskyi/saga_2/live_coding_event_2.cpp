#include<iostream>
#include<fstream>

using namespace std;

double GetTarifs(string s)
{
    ifstream file1;
    ifstream file2;
    ifstream file3;
    string value;
    double tarif;

    if(s == "meter")
    {
        file1.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/price_per_meter.txt");
        getline(file1, value);
        tarif = stod(value);
        file1.close();
    }
    else if(s == "miles_US")
    {
        file2.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/price_per_mile.txt");
        getline(file2, value);
        tarif = stod(value);
        file2.close();
    }
    else if(s == "miles")
    {
        file2.open("C:/Users/sabob/projects/ai_programming_playground_2024/ai_12/oleksandr_bobrovytskyi/saga_2/price_per_mile_us.txt");
        getline(file3, value);
        tarif = stod(value);
        file3.close();
    }

    return tarif;
}

string GetIdentificator(string Name)
{
    string temp, ID;
    int code;

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
        ID.push_back(code);
    }

    return ID;
}

int main()
{
    int meter, miles_US, miles;
    string UserName, units, convertBonus;
    double distance, tarif;
    int ID;

    cout << "Enter your name" << endl;
    cin >> UserName;

    cout << "Enter the distance to the destination" << endl;
    cin >> distance;

    cout << "Choose meter/miles_US/miles" << endl;
    cin >> units;

    tarif = GetTarifs(units);

    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convertBonus;

    ID = stoi(GetIdentificator(UserName));

    return 0;
}