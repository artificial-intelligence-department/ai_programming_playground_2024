#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

enum Measurment {
        METRE,
        IMILE,
        USMILE
    };

void nameid (string &name) {
    int *id = new int[sizeof(name) / sizeof(name[0])];
    int i = 0;
    for (char c : name) {
        id[i] = c * 0.4;
        ofstream fileInput("nameId.txt", ios::app);
        if (fileInput.tellp() == 0) {
            fileInput << id[i];
        }
        i++;
    }
}

bool isPalindrome(int &num) {
    int orig = num;
    int revers = 0;
    while (orig != 0) {
        int digit = orig % 10;
        revers = revers * 10 + digit;
        orig /= 10;
    }
    return num == revers;
}

double toMetre(int &dist, int &measurement) {
    switch (measurement) {
        case 0:
            return (double)dist;
            break;
        case 1:
            return dist / 1609.344;
            break;
        case 2:
            return dist / 1609.347;
            break;
    }
    return 0.0;
}

int main() {
    string name;
    int dist;
    int measurement;
   
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the distance: ";
    cin >> dist;
    cout << "Enter the measurement system(UKmile(1)/USmile(2)/metre(3)): ";
    cin >> measurement;
    if (measurement != 1 && measurement != 2 && measurement != 3) {
        cout << "Invalid measurement.";
        return 0;
    }
    measurement--;
    double distInMetres = toMetre(dist, measurement);
    cout << distInMetres;
    return 0;
}