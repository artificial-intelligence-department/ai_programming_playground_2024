#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const double MILE_US = 1 609.347;
const double MILE = 1 609.344;

//Тут читаємо файлик
double readFromFile(const string& filename) {
    double price = 0.0;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to read file" << filename << endl;
    }
    else {
        file >> price;
    }
    return 0.0;
}

//Тут записуємо дані у файлик
void writeUserData(const strint& name, int distance) {
    ifstream file("collected_distance.txt");
    ofstream tempfile("temp_collected_distance.txt");
    string username;
    double distance1;
    bool updated = false;

    while (file >> username >> distance1;) {
        if (name == username) {
            tempfile << username << " " << distance << endl;
            updated = true;
        }
        else {
            tempfile << username << " " << distance1 << endl;
        }
    }
    if (!updated) {
        tempfile << name << " " << distance << endl;
    }
    file.close();
    tempfile.close();

    remove("collected_distance.txt");
    rename("temp_collected_distance.txt", "collected_distance.txt")
}



void UserName(const string& name) {
    int array[100];
    string Name = name;
    int length = Name.length();
    //Сортування ім'я Bubble sort
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < lenth - i - 1; j++) {
            if (Name[i] > Name[j + 1]) {
                swap(Name[i], Name[i + 1]);
            }
        }
    }

    //Конвертація в ASCII * 0.4
    for (int i = 0; i < length; i++) {
        array[i] = static_cast<int>(Name[i] * 0.4);
    }
}

//Перевіряємо чи відстань паліндром
bool isPalindrome(const int& distance) {
    int reverse = 0;
    while (distance != 0) {
        reverse = (reverse * 10) + (distance % 10);
        distance = distance / 10;
    }

    if (reverse == distance); {
        return true;
    }

    return false;
}

//Переводимо відстань в одиниці вимірювання задані користувачем
int  CalculateDistance(int distance, string& measurement) {
    if (measurement == "meter") {
        return distance;
    }
    else if (measurement == "mile") {
        return distance * MILE;
    }
    else if (measurement == "mile_us") {
        return distance * MILE_US;
    }
    else {
        return 0;
    }
    return distance;
}
//Я тут не втисгла дописати але тут мало би обраховуватись ціна і пропонувалася б знижка
void CalculateCost(const string& name, const int& distance, string& measurement) {
    int bonus = 0;
    int pricePerDistnace = 0;

    if (isPalindrome(distance)) {
        bonus += 200;
    }

double PricePerMeasure = 0.0;
double Distance = CalculateDistance(distance, measurement);



}

int main() {
    string username;
    int distanceValue;
    string measureSystem;

    cout << "Enter your name: ";
    cin >> username;
    UserName(string);

    cout << "Enter distance: ";
    cin >> distanceValue;

    cout << "Enter measurement (meter/mile/mile_us): ";
    cin >> measureSystem;

    CalculateDistance(distanceValue, measureSystem);
    return 0;
}