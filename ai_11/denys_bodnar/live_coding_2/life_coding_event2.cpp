#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

const double impireMileToMeters = 1609.344;
const double usMileToMeters = 1609.347;
const double meterToMeret = 1;

bool palindrom (int distance) {
    string str = to_string(distance);
    string reversedStr = str;
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool priceFromFile (const string& filename, double& price) {
    ifstream file(filename);
    if (file.is_open()) {
        string label;
        file >> label >> price;
        file.close();
        return true;
    } else {
        cout << "Такого файлу не існує!" << filename << endl;
        return false;
    }
}

double simulateMoneyPrecision(double value) {
    return round(value * 100.0) / 100.0;
}

void bubbleSort (string& name) {
    for (size_t i = 0; i < name.length() - 1; i++) {
        for (size_t j = 0; j < name.length() - i - 1; j++) {
            if (name[j] > name[j + 1]) {
                char temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }
}

void generateUserID (const string& name, int* userIDarr, int& size) {
    string sortedName = name;
    bubbleSort(sortedName);

    size = sortedName.length();
    for (int i = 0; i < size; i++) {
        userIDarr[i] = static_cast<int>(sortedName[i]) * 0.4;
    }
}


int main () {
    double mileTometer = 1609.344;
    double mileUsTometer = 1609.347;

    string userName;


    cout << "Введіть ваше ім'я: ";
    cin >> userName;

    int maxNameLength = 100;
    int userIDarr[maxNameLength];
    int idSize = 0;
    generateUserID (userName, userIDarr, idSize);

    cout << "Ваш ідентифікатор: ";
    for (int i = 0; i < userIDarr; i++) {
        cout << userIDarr[i] << " ";
    }
    cout << endl;

    double priceMeter , priceMile, priceMileUS;
    if (!priceFromFile("price_per_meter.txt", priceMeter) || !priceFromFile("price_per_male.txt", priceMile) || !priceFromFile("price_per_mile_us", priceMileUS)) {
        return 1;
    }

    double totalDistanceMeters = 0;
    double bonusDistanceMeters = 0;

    while (true) { 
        double distanceValue;
        string measurementSystem;

        cout << "Введіть відстань: ";
        cin >> distanceValue;

        cout << "Введіть одиницю виміру (meter/mile/mile_us): ";
        cin >> measurementSystem;

        double conversionRate = 0;
        double pricePerUnit = 0;

        if (measurementSystem == "mile") {
            conversionRate = impireMileToMeters;
            pricePerUnit = priceMile;
        } else if (measurementSystem == "mile_us") {
            conversionRate = usMileToMeters;
            pricePerUnit = priceMileUS;
        } else if (measurementSystem == "meter") {
            measurementSystem = meterToMeret;
            pricePerUnit = priceMeter;
        } else {
            cout << "Ви ввели невідому одиницю вимірювання!" << endl;
            continue;
        }

        double deliveryDistanceInMeters = distanceValue * conversionRate;
        totalDistanceMeters += deliveryDistanceInMeters;

        double totalPrice = simulateMoneyPrecision(distanceValue * pricePerUnit);
        cout << "Вартість доставки: " << totalPrice << "$" << endl;
        
        if (palindrom(static_cast<int>(distanceValue))) {
            bonusDistanceMeters += 200000; // 200 км бонусу в метрах
            cout << "Відстань є паліндромом! Вам нараховано бонус 200км" << endl;
        }

    }

    return 0;
}