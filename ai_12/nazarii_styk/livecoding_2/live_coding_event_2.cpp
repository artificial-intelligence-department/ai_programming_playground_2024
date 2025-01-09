#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void BubbleSort(string& name)
{
    int n = name.length();

    for (int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(name[j] > name[j + 1])
            {
                swap(name[j], name[j+1]);
            }
        }
    }
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

void GenerateUderID(string& userName)
{
    int max = userName.length();
    char nameInChar[max];
    int name[];

    for (int i = 0; i < max; i++)
    {
        nameInChar[i] = userName[i];
    }

    for (int i = 0; i < max; i++)
    {
        int value = int(nameInChar[i]);
        name[i] = value * 0.4;     
    }

    PrintArray(name, max);


}

float ConvertToMeters(float distanceValue, string measurementSystem)
{
    if(measurementSystem == "meter")
    {
        return distanceValue;
    }
    else if (measurementSystem == "mile")
    {
        return distanceValue * 1609.344; 
    }
    else if (measurementSystem == "mile_us")
    {
        return distanceValue * 1609.347; 
    }
    
}

int main()
{
    string userName, measurementSystem;
    float distanceValue;
    cout << "Введіть ваше ім'я: " << endl;
    cin >> userName;
    cout << "Введіть відстань: ";
    cin >> distanceValue; 
    // while (measurementSystem != "meter" || measurementSystem != "mile" || measurementSystem != "mile_us")
    // {
        cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
        cin >> measurementSystem;
    // }

    BubbleSort(userName);
    cout << userName << endl;

    GenerateUderID(userName);


    // ConvertToMeters(distanceValue, measurementSystem);
    // cout << distanceValue << endl;
    

    return 0;
}

// measurementSystem != "meter" || measurementSystem != "mile" || measurementSystem != || "mile_us"