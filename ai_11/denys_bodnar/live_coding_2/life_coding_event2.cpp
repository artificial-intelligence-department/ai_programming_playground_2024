#include <iostream>
#include <cmath>
#include <string>

using namespace std;

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
    double distanceValue;

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


    cout << "Введіть відстань: ";
    cin >> distanceValue;

    cout << "Введіть одиницю виміру (meter/mile/mile_us): ";


    return 0;
}