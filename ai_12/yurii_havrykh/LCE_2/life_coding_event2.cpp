#include <iostream>
#include<fstream>
#include<sstream>
#include<cmath>

using namespace std;

const int variant = 33;//цілочисельна константа

struct User {//своя Структура
    string id;
    double bonuses;
};


double get_cost(string measurementSystem, double dist) {//функція читання з файлу
    double cost, result_cost;
    if (measurementSystem == "meter") {
        ifstream file("price_per_meter.txt");
        file >> cost;
        result_cost = cost * dist;
        file.close();
    } else if (measurementSystem == "mile") {
        ifstream file("price_per_mile.txt");
        file >> cost;
        result_cost = cost * dist;
        file.close();
    } else if (measurementSystem == "mile_us") {
        ifstream file("price_per_mile.txt_us");
        file >> cost;
        result_cost = cost * dist;
        file.close();
    } else return -1;
    return result_cost;
}

bool is_palindrom(string dist, int l, int r) {//Рекурсивна функція
    bool result;
    if (l < r)
        result = (dist[l] == dist[r]) & (is_palindrom(dist, l + 1, r - 1));
    else result = true;
    return result;
}

double conver_meters(double oldValue, string measurementSystem) {
    double newValue;
    if (measurementSystem == "meter") newValue = oldValue;
    else if (measurementSystem == "mile") newValue = oldValue * 1609.344;
    else if (measurementSystem == "mile_us") newValue = oldValue * 1609.347;
    return newValue;
}

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

string get_id(string name) {
    string id = "";
    int n = name.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (name[i] > name[j])
                swap(name[i], name[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        id += to_string(int((name[i] - '0') * 0.4));
    }
    return id;
}

double read_bonuses_file(string id) {
    ifstream file("collected_distance.txt");
    User array[20];
    string line;
    int i = 0;
    double bonuses = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        ss >> array[i].id;
        ss >> array[i].bonuses;
        i++;
        if (array[i].id == id)
            bonuses += array[i].bonuses;
    }
    return bonuses;
}

int main() {
    while (true) {
        cout << "Щоб зупинити програму введіть -1, в іншому випадку введіть ваше ім'я: ";
        string userName;
        cin >> userName;
        if (userName == "-1") exit(0);
        double distanceValueOld;
        cout << "Введіть відстань: ";
        cin >> distanceValueOld;
        string measurementSystem;
        cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
        cin >> measurementSystem;
        string ID=get_id(userName);
        cout <<"Ваше ID" << ID << endl;;
        double distanceValue = conver_meters(distanceValueOld, measurementSystem);

        double deliveryDistanceInMeters = simulateMoneyPrecision(distanceValue);
        double totalPrice = simulateMoneyPrecision(get_cost(measurementSystem, distanceValueOld));
        string distStr = to_string(int(distanceValue));
        bool is_bonus;
        is_bonus = is_palindrom(distStr, 0, distStr.size() - 1);

        cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "m" << endl;
        //cout << "Ваша знижка: " << discount << "$" << endl;
        cout << "Накопичена відстань: " << read_bonuses_file(ID) << "km" << endl;
        cout << "Вартість відправки: " << totalPrice << "$" << endl;
        if (is_bonus) cout << "Ви отримали 200 бонусних кілометрів" << endl;

        cout << endl;
    }


}