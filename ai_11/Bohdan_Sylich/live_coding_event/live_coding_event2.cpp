#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const double mill_meters = 1609.344;
const double usmill_meters = 1609.347;
const double meters = 1.0;
string sortString(const string &str){
    string sortedStr = str;
    for (size_t i = 0; i < sortedStr.length(); ++i){
        for (size_t j = j = i + 1; j < sortedStr.length(); ++j){
            if (sortedStr[i] > sortedStr[j]){
                char temp = sortedStr[i];
                sortedStr[i] = sortedStr[j];
                sortedStr[j] = temp;
            }
        }
    }
    return sortedStr;
    }
void generateuserID(const string &name, int userID[]){
string sortName = sortString(name);
for(int i = 0; i < 3; i++){
    userID[i] = (sortName[i] * 0.4);
}
}

bool isPalindrome(const string &str){
    int len = str.length();
    for (int i = 0; i < len / 2; i++){
        if (str[i] !=str[len - i - 1]) return false;
    }
    return true;
}

double convertToMeters(double distance, const string &unit){
    if (unit == "mi") return distance*mill_meters;
    if (unit == "mi_us") return distance*usmill_meters;
    return distance; // if meters
}
void saveBonusToFile(const string &filename, const string &userid, double bonusDiastance){
    ofstream file(filename, ios::out);
    if (file.is_open()){
        file << userid << " " << bonusDiastance << endl;
        file.close();
    } else{
        cout << "ERROR, can't open the file" << endl;
    }
}
double loadBonusFromFile(const string &filename, const string &userid){
    ifstream file(filename, ios::in);
    string storedUserId;
    double storedBonusDistance = 0.0;

    if (file.is_open()){
        while (file >> storedUserId >> storedBonusDistance){
            if (storedUserId == userid){
                file.close();
                return storedBonusDistance;
            }
        }
        file.close();
    } else { cout << "Файл для бонусів не знайдений";} return 0.0;
}
    double calculationCost(double distanceInMeters, double &bonusDistance, bool useBonuses){
        if (isPalindrome(to_string(static_cast<int>(distanceInMeters)))){
            bonusDistance += 200.0;
        }

        double cost = distanceInMeters * 0.0005;
        if (useBonuses){
            double discount = static_cast<int>(bonusDistance/100.0);
            cost -= discount;
            bonusDistance -= discount * 100.0;
            if (cost < 0) cost = 0.0;
        }
        return cost;
    }
    
int main(){
    string name,unit,file="bonus_data.txt";
    cout << "enter your Name: ";
    cin >> name;

    int userid[3];
    generateuserID(name, userid);
    string userIdStr = to_string(userid[0]) + to_string(userid[1]) + to_string(userid[2]);

    double totalBonusDistance = loadBonusFromFile(file,userIdStr);

    cout << "Поточні бонуси користувача " << userIdStr << ": " << totalBonusDistance << " m" << endl;

    double distance;
    cout << "Введіть відстань: ";
    cin >> distance;
    cout << "Оберіть одиницю вимірювання (mi/mi_us/m): ";
    cin >> unit;

    char useBonusesChoice;
    cout << "Бажаєте використати бонуси для знижки? (y/n): ";
    cin >> useBonusesChoice;
    bool useBonuses = (useBonusesChoice == 'y' || useBonusesChoice == 'Y');

    double distanceInMeters = convertToMeters(distance, unit);
    double cost = calculationCost(distanceInMeters, totalBonusDistance, useBonuses);

    cout << "Вартість доставки: " << cost << "$" << endl;
    cout << "Оновлені бонуси: " << totalBonusDistance << " m" << endl;

    saveBonusToFile(file, userIdStr, totalBonusDistance); 

    return 0;
}