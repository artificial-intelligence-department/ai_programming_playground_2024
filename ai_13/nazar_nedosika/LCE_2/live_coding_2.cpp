#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

const double MILE_TO_METERS = 1609.344;
const double US_MILE_TO_METERS = 1609.347;
const double METERS_TO_KM = 0.001;

bool isPalindrom(int distance){
    string str = to_string(distance);
    string reversed_str = str;
    reverse(reversed_str.begin(), reversed_str.end());
    return str == reversed_str;
}

vector<int> generateUserID(const string& name){
    string sorted_name = name;
    sort(sorted_name.begin(), sorted_name.end());

    vector<int> ascii_values;
    for (char c : sorted_name)
    {
        ascii_values.push_back(static_cast<int>(c) * 0.4);
    }

    vector<int> selected_values;
    for (int i = 1; i <= 3 && i < ascii_values.size(); i++)
    {
        selected_values.push_back(ascii_values[i]);
    }
    
    return selected_values;
}

vector<pair<string, double>> loadUserData(const string& filename){
    vector<pair<string, double>> userData;
    ifstream file(filename);
    if(file.is_open()){
        string name;
        double distance;
        while(file >> name >> distance){
            userData.emplace_back(name, distance);
        }
        file.close();
    }
    return userData;
}

void saveUserData(const string& filename, const vector<pair<string, double>>& userData){
    ofstream file(filename);
    if(file.is_open()){
        for (const auto& entry : userData)
        {
            file << entry.first << " " << entry.second << endl;
        }
        file.close();
    }
}

int main(){
    const string filename = "userdata.txt";
    vector<pair<string, double>> userData = loadUserData(filename);

    string name;
    cout << "Введіть імя: ";
    cin >> name;

    double accumulatedDistance = 0;
    bool userExists = false;

    vector<int> userID = generateUserID(name);
    
    double distance;
    string unit;
    cout << "Введіть відстань: ";
    cin >> distance;
    cout << "Оберіть одиницю вимірювання(mi, mi_Us, m): ";
    cin >> unit;

    if(unit == "mi"){
        distance *= MILE_TO_METERS * METERS_TO_KM;
    }
    else if(unit == "mi_Us"){
        distance *= US_MILE_TO_METERS * METERS_TO_KM;
    }
    else if(unit == "m"){
        distance *= METERS_TO_KM;
    }
    else{
        cout << "Невідома одиниця виміру";
    }

    if(isPalindrom(static_cast<int>(distance))){
        distance += 200;
        cout << "Додано +200км бонусів" << endl;
    }

    accumulatedDistance += distance;

    if(userExists){
        for (auto& entry : userData)
        {
            if(entry.first == name){
                entry.second = accumulatedDistance;
                break;
            }
        }
        
    }
    else{
        userData.emplace_back(name, accumulatedDistance);
    }

    int discount = static_cast<int>(distance)/100;
    cout << "Накопичено знижку: " << discount << "$" << endl;

    saveUserData(filename, userData);

    return 0;
}