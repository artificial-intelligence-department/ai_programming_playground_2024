#include <iostream>
#include <iomanip>
#include <string>  // для size()
#include <sstream>
#include <cmath>
#include <fstream>
using namespace std;

const double mi = 1609.344;
const double mi_US = 1609.347;
const int METER = 1;

// bonuses:

bool is_palindrome(int distance){
    string str = to_string(distance);
    string rev = str;
    for(int i = 0; i < str.size(); ++i){
        rev[i] = str[str.size() - i - 1];
    }
    return str == rev;
}

void generate_identificator(string userName, double arr_ID[], int &size){
    size = userName.size();
    for(int i = 0; i < size - 1; ++i){
        for(int j = 0; j < size - i - 1; ++j){
            if(userName[j] > userName[j + 1]){
                char temp = userName[j];
                userName[j] = userName[j + 1];
                userName[j + 1] = temp;               // Buble sort
            }
        }
    }
    for(int i = 0; i < size; ++i){
        arr_ID[i] = static_cast<int>(userName[i] * 0.4);  // ASCII
    }
}

double convertDistance(double distance, string measurementSystem){
    if(measurementSystem == "mile"){
        return distance * mi;
    } else if(measurementSystem == "mile_us"){
        return distance * mi_US;
    } else if(measurementSystem == "meter"){
        return distance * METER;
    } else{
        cout << "Undefined measurement system! \n";
        return distance;
    }
}

void write_to_file(string userName, double arr_ID[], int size, double deliveryDistanceInMeters, bool is_palindrome, const char *filename, double disc){
    ofstream write_file(filename);
    if(!write_file){
        cerr << "Can't open file for writing \n";
        return;
    }

    write_file << "ID користувача: \n";
    for(int i = 0; i < size; i++){
        write_file << arr_ID[i] << " ";
    }
    write_file << endl;

    write_file << "Відстань поточної доставки: " << deliveryDistanceInMeters << " m" << endl;
    cout << "Ваша знижка: " <<  disc << "$" << endl;

    if(is_palindrome){
        write_file << "Ваша відстань є паліндромом, тож ви маєте + 200km бонусів \n";
        deliveryDistanceInMeters += 200000; 
        double deliveryDistanceInKiloMeters = deliveryDistanceInMeters / 1000;
        write_file << "Now your distance is " << deliveryDistanceInKiloMeters  << " km" << endl;
    }
    write_file.close();
}

double discount(double distanceValue){
    double discount = distanceValue / 100000;
    return discount;
}

int main(){

    string userName;
    cout << "Введіть ваше ім'я: \n";
    cin >> userName;

    double distanceValue;
    cout << "Введіть відстань: (у метрах) \n";
    cin >> distanceValue;

    string measurementSystem;
    cout << "Введіть одиницю виміру (meter/mile/mile_us): \n";
    cin >> measurementSystem;

    char convertBonus;
    cout << "Бажаєте конвертувати бонуси у відстань (y/n)?";
    cin >> convertBonus;

    double arr_ID[100];
    int size = 0;
    cout << "ID користувача: \n";
    generate_identificator(userName, arr_ID, size);

    for(int i = 0; i < size; i++){
        cout << arr_ID[i] << " ";
    }
    cout << endl;

    double deliveryDistanceInMeters = convertDistance(distanceValue, measurementSystem);
    cout << "Відстань поточної доставки: " << deliveryDistanceInMeters << " m" << endl; 

    double disc = discount(distanceValue);
    cout << "Ваша знижка: " <<  disc << "$" << endl;

    if(is_palindrome(static_cast<int>(deliveryDistanceInMeters))){
        cout << "Ваша відстань є паліндромом, тож ви маєте + 200km бонусів\n";
        deliveryDistanceInMeters += 200000; // in meters
    }
    double deliveryDistanceInKiloMeters = deliveryDistanceInMeters / 1000;
    cout << "Накопичена відстань: " << deliveryDistanceInKiloMeters << " km" << endl;

    write_to_file(userName, arr_ID, size, deliveryDistanceInMeters, is_palindrome, "collected_distance.txt", disc);

    return 0;
}