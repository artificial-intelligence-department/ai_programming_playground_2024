#include <iostream>
#include <cmath> 
using namespace std;

double calculateArea(double radius) {
    return M_PI * radius * radius;
}

double calculateArea(double length, double width) {
    return length * width;
}

double calculateArea(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    int choice;
    cout << "введіть фігуру (1 - коло, 2 - прямокутник, 3 - трикутник): ";
    cin >> choice;

    if (choice == 1) {
        double radius;
        cout << "введіть радіус: ";
        cin >> radius;
        cout << "Площа кола: " << calculateArea(radius) << endl;
    } 
    else if (choice == 2) {
        double length, width;
        cout << "введіть довжину та ширину: ";
        cin >> length >> width;
        cout << "Площа прямокутника: " << calculateArea(length, width) << endl;
    } 
    else if (choice == 3) {
        double base, height;
        cout << "введіть основу та висоту: ";
        cin >> base >> height;
        cout << "Площа трикутника: " << calculateArea(base, height, true) << endl;
    } 
    else {
        cout << "помилка!" << endl;
    }

    return 0;
}
