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

double




}
