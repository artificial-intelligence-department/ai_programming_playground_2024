#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string filename = "file_ife_coding_event2.txt";

int main(){

    string userName, measurementSystem;
    double distanceValue;

    cout << "Введіть ваше ім'я: ";
    cin >> userName;

    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> measurementSystem;

    double dist_meter;

    if (measurementSystem == "mile")
    {
        dist_meter = distanceValue * 1609.344;
    }
    else if (measurementSystem == "mile_us")
    {
        dist_meter = distanceValue * 1609.347;
    }
    else if (measurementSystem == "meter")
    {
        dist_meter = distanceValue;
    }
    else {
        cerr << "Введено хибний варіант вибору!";
    }
    int n = userName.length();


    // Сортування імені
    int swap_count = 1;

    while (swap_count > 0)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (int(userName[i]) > int(userName[i+1]))
            {
                swap(userName[i], userName[i+1]);
                ++swap_count;
            }
        }
        --swap_count;
    }

    int id_code_arr[n];
    int id_code_int;

    for (int i = 0; i < n; i++)
    {
        id_code_int = int(userName[i]);
        id_code_arr[i] = id_code_int * 0.4;
    }
    

    fstream file(filename, ios::in | ios::out | ios::trunc);

    for (int i : id_code_arr)
    {
        file << to_string(i);
    }
    
    file << " " << dist_meter << endl;
    
}
