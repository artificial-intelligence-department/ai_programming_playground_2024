#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct User {
    string name;
    int ID;
    double distance;
};

bool is_palyndrome(int number) {
    int reversed = 0, original = number;
    while (number > 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed == original;
}

int calculate_discount(int kilometers) {
    if (kilometers < 100) {
        return 0;
    }
    return 1 + calculate_discount(kilometers - 100);
}

double convert_distance(double distance, const string& unit_changes) {
    if (unit_changes == "mi") {
        return distance * 1609.344;
    }
    if (unit_changes == "mi_US") {
        return distance * 1609.344;
    }
    return distance;
}

int convert_distance(int distance, const string& unit_changes) {
    return static_cast<int>(convert_distance(static_cast<double>(distance), unit_changes));
}

int main() {
    const int bonus_km = 200;
    User user = {"Yuliia", 0, 0.0};

    string sorted_name = user.name;
    sort(sorted_name.begin(), sorted_name.end());

    size_t name_size = sorted_name.size();
    int* values = new int[name_size];
    for (size_t i = 0; i < name_size; ++i) {
        values[i] = static_cast<int>(sorted_name[i]) * 0.4;
    }

    int array[3];
    for (int i = 0; i < 3; ++i) {
        array[i] = values[i];
    }

    float double_array[5][3];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            double_array[i][j] = i * j + 0.5f;
        }
    }

    ofstream outfile("result.txt");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 3; ++j) {
            outfile << double_array[i][j] << " ";
        }
        outfile << endl;
    }
    outfile.close();

    ifstream infile("result.txt");
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
    }
    infile.close();

    int distance;
    string unit;
    do {
        cout << "Введіть межі та одиницю (або -1 щоб вийти): ";
        cin >> distance;
        if (distance == -1) break;
        cin >> unit;

        double converted_distance = convert_distance(distance, unit);
        cout << "Конвертована дистанція: " << converted_distance << " метрів\n";
        if (is_palyndrome(static_cast<int>(converted_distance))) {
            user.distance += bonus_km;
            cout << "Бонус за паліндромність: " << bonus_km << " кільметрів.\n";
        }
        user.distance += distance;
        cout << "Повна дистанція: " << user.distance << " метрів.\n";
    } while (true);

    int discount = calculate_discount(static_cast<int>(user.distance / 1000));
    cout << "Знижка: " << discount << endl;

    return 0;
}