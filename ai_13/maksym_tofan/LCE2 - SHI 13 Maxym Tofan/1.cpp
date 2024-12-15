#include <iostream>
#include <iomanip>   // Для виведення з фіксованою точністю
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>

using namespace std;

const double MILE_TO_METERS = 1609.344;
const double MILE_US_TO_METERS = 1609.347;
const int BONUS_KM = 200;
const int DISCOUNT_KM = 100;


bool is_palindrome(int distance) {

   string dist_str = to_string(distance);
   string reversed_str = dist_str;
   int n = dist_str.length();
   for (int i = 0; i < n/2; i++) {

   if (dist_str[i] != dist_str[n-1 -i]) {

return false;

   }

   }
return true;
}


void simple_sort(string &str) {

 
   int n = str.size();
         for (int i = 0; i<n -1; i++) {

             for (int j = i+1; j < n; i++)  {

                 if(str[i > str[j]]) {

                     swap(str[i], str[j]); 

                }

            }
        } 
 }


string generate_user_id(const string& name) {

 string sorted_name = name;
 simple_sort(sorted_name);
 stringstream ss;
 for (char c : sorted_name) {

ss << fixed << setprecision(1) << (double(int(c))  * 0.4) << " ";


 }
return ss.str();
}


double convert_distance(double distance, const string& from_unit, const string& to_unit) {

if (from_unit == "meter" && to_unit == "mile") {

 return distance/MILE_TO_METERS;

}

if (from_unit == "mile" && to_unit == "meter") {

 return distance * MILE_TO_METERS;

}

if (from_unit == "mile_us" && to_unit == "meter") {

 return distance*MILE_US_TO_METERS;

}

if (from_unit == "meter" && to_unit == "mile_us") {

 return distance/MILE_US_TO_METERS;

}

return distance;

}

double read_price_from_file(const string& filename)   {



    ifstream file(filename);
    double price;

    if (file.is_open()) {
        file >> price;
        file.close();
    } else {
        cerr << "Не вдалося відкрити файл: " << filename << endl;
        return 0;
    }
    return price;
}


class User {
public:
string name;
string id;
double total_distance;
double total_bonuses;
double price_per_meter;
double price_per_mile;
double price_per_mile_us;

User(string user_name) : name(user_name), total_distance(0), total_bonuses(0) {


    id = generate_user_id(user_name);
    price_per_meter = read_price_from_file("price_per_meter.txt");
    price_per_mile = read_price_from_file("price_per_mile.txt");
    price_per_mile_us = read_price_from_file("price_per_mile_us.txt");


}

void add_distance(double distance, const string& unit) {

total_distance += convert_distance(distance, unit, "meter");
if (is_palindrome(int(distance))) {

    total_bonuses += BONUS_KM;
}

}

int get_discount() {
    return total_distance / (100000);
}


void apply_bonuses() {
int km_for_discount = get_discount();
if (km_for_discount > 0) {
    cout << "ви отримали: " << km_for_discount << "$ знижки!" << endl;
    total_distance -= km_for_discount * 100000;
} else {
    cout << "нема достатньо бонусів для знижки" << endl;
}
}

double convert_bonuses_to_distance() { 
    return total_bonuses * 1000;
}

double calculate_shipping_cost(const string& unit)  {

    double price = 0;
    if(unit == "meter") {

        price = total_distance * price_per_meter;
    } else if (unit == "mile") {
        price = convert_distance(total_distance, "meter", "mile") * price_per_mile;
    } else if (unit == "mile_us") {
        price = convert_distance(total_distance, "meter", "mile_us") * price_per_mile_us;
    }
    return price;
}

void show_info() {
    cout << "Ідентифікатор користувача: " << id << endl;
    cout << "Загальна накопичена відстань: " << total_distance / 1000 << "км" << endl;
    cout << "Накопичені бонуси: " << total_bonuses << "км" << endl;
}


};


int main() {

    string userName, measurementSystem, convertBonus;


double distanceValue;
cout << "Введіть ваше імя: ";
cin >> userName;

User user(userName);

while (true)  {


    cout << "\nОберіть опцію: " << endl;
    cout << "1. Додати відстань" << endl;
    cout << "2. Подивитись відстань" << endl;
    cout << "3. Використати бонуси" << endl;
    cout << "4. Вийти" << endl;



    int choice;

    cout << "Ваш вибір: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Введіть відстань: ";
        cin >> distanceValue;


        cout << "Введіть відстань: ";
        cin >> distanceValue;

        cout << "Введіть одииниці виміру (meter/mile/mile_us): ";
        cin >> measurementSystem;

        user.add_distance(distanceValue, measurementSystem);


        cout << "Бажаєте конвертувати бонуси у відстань (y/n)? ";
        cin >> convertBonus;

              if (convertBonus == "y") {
                double bonusDistance = user.convert_bonuses_to_distance();
                cout << "Ваші бонуси дорівнюють: " << bonusDistance << " м" << endl;
            }

            // Обчислення вартості доставки
            double deliveryDistanceInMeters = user.total_distance;
            double totalPrice = user.calculate_shipping_cost(measurementSystem);
            double discount = user.get_discount();
            double deliveryDistanceInKiloMeters = deliveryDistanceInMeters / 1000;

            cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << "м" << endl;
            cout << "Ваша знижка: " << discount << "$" << endl;
            cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << "км" << endl;
            cout << "Вартість відправки: " << totalPrice - discount << "$" << endl;
        } else if (choice == 2) {
            user.show_info();
        } else if (choice == 3) {
            user.apply_bonuses();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
        }
    }

    return 0;
    }





