#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))

const double mi = 1609.344; // (v5), v3
const double mi_US = 1609.347;

int * get_id(const char *name) // v14
{
    int length = strlen(name); // v1
    char *arr = new char[length + 1]; // v6
    memcpy(arr, name, length + 1);
    for (int i = 0; i < length - 1; i++) // v10
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    int *id = new int[length];
    for (int i = 0; i < length; i++)
    {
        id[i] = arr[i] * 0.4; // v15
    }
    return id;
}

string id_to_str(int *id, int length)
{
    stringstream ss;
    for (int i = 0; i < length; i++)
    {
        ss << id[i];
    }
    return ss.str();
}

double simulate_precision(double value) 
{
    return round(value * 100.0) / 100.0;
}

double calculate_price(double distance, double price)
{
    return simulate_precision(distance * price);
}

int calculate_bonuses(double distance_in_m)
{
    int bonuses = (int)distance_in_m / 1000;
    int check_pal = distance_in_m;
    long long check_pal1 = 0, check_pal2 = 0;
    int i = 0;
    while (check_pal) // v9
    {
        check_pal2 *= 10;
        check_pal1 += (check_pal % 10) * pow(10, i++);
        check_pal2 += check_pal % 10;
        check_pal /= 10;
    }
    if (check_pal1 == check_pal2)
    {
        bonuses += 200;
    }
    return bonuses;
}

int main()
{
    string name;
    double distance, distance_in_m;
    string units;
    string convert;
    double price_per_m, price_per_mile, price_per_mile_us, price;
    fstream fs;

    fs.open("price_per_meter.txt", fstream::in); // v16
    if (fs)
    {
        fs >> price_per_m;
        fs.close();
    }
    else
    {
        cerr << "ERROROPENINGprice_per_meter.txt!!!!";
        exit(1);
    }

    fs.open("price_per_mile.txt", fstream::in);
    if (fs)
    {
        fs >> price_per_mile;
        fs.close();
    }
    else
    {
        cerr << "ERROROPENINGprice_per_mile.txt!!!!";
        exit(1);
    }

    fs.open("price_per_mile_us.txt", fstream::in);
    if (fs)
    {
        fs >> price_per_mile_us;
        fs.close();
    }
    else
    {
        cerr << "ERROROPENINGprice_per_mile_us.txt!!!!";
        exit(1);
    }

    cout << "Введіть ваше ім'я: "; // v18
    cin >> name;

    cout << "Введіть відстань: ";
    cin >> distance;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
    cin >> units;

    if (units == "meter")
    {
        price = price_per_m;
        distance_in_m = distance;
    }
    if (units == "mile")
    {
        price = price_per_mile;
        distance_in_m = distance * mi;
    }
    if (units == "mile_us")
    {
        price = price_per_mile_us;
        distance_in_m = distance * mi_US;
    }

    int *id = get_id(name.c_str());
    cout << id_to_str(id, name.size());
    fs.open("live_coding_2.dat", fstream::in);
    string id_str;
    int current_bonuses;
    if (fs)
    {
        fs >> id_str >> current_bonuses;
        fs.close();
    }
    else
    {
        id_str = id_to_str(id, name.size());
        current_bonuses = 0;
    }
    if (id_str != id_to_str(id, name.size()))
    {
        id_str = id_to_str(id, name.size());
        current_bonuses = 0;
    }

    price = calculate_price(distance, price);
    double discount = MIN(simulate_precision(current_bonuses / 100.0), price);
    current_bonuses += calculate_bonuses(distance_in_m);
    
    cout << endl << "Відстань поточної доставки: " << distance_in_m << "m" << endl;
    cout << "Вартість відправки: " << price << "$" << endl;
    cout << "Ваші бонуси: " << current_bonuses - calculate_bonuses(distance_in_m) 
        << " (+ " << calculate_bonuses(distance_in_m) << ")" << endl;
    cout << "Потенційна знижка: " << discount << "$" << endl;
    
    cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
    cin >> convert;

    if (convert[0] == 'y' || convert[0] == 'Y')
    {
        cout << "Остаточна ціна: " << price - discount << "$" << endl;
        current_bonuses -= (int)(discount*100);
        cout << "Ваші бонуси: " << current_bonuses << endl;
    }
    fs.open("live_coding_2.dat", fstream::out);
    fs << id_str << "\t" << current_bonuses;
}