#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double angle(double a, double b, double c) {
    return acos((b*b + c*c - a*a) / (2 * b * c)) * (180.0 / M_PI);
}

void angles(const vector<double>& sides) {
    int n = sides.size();
    if (n < 3) {
        cout << "Необхідно принаймні 3 сторони для обчислення кутів" << endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        cout << " " << sides[i];
    }
    cout << endl;

    if (n == 3) {
        double A = angle(sides[0], sides[1], sides[2]);
        double B = angle(sides[1], sides[0], sides[2]);
        double C = 180.0 - A - B;
        cout << "Кути трикутника: A = " << A << ", B = " << B << ", C = " << C << endl;
        return;
    }

    bool isRegular = true;
    for (int i = 1; i < n; ++i) {
        if (fabs(sides[i] - sides[0]) > 1e-6) {
            isRegular = false;
            break;
        }
    }

    if (isRegular) {
        double angleValue = ((n - 2) * 180.0) / n;
        cout << "Кути правильного " << n << "-кутника: ";
        for (int i = 0; i < n; ++i) {
            cout << angleValue << " ";
        }
        cout << endl;
        return;
    } else {
        cout << "Обчислення кутів для нерівностороннього n-кутника ще не реалізовано" << endl;
    }
}

int main() {
    double sides1[] = {3.0, 4.0, 5.0};
    double sides2[] = {3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0, 3.0};
    double sides3[] = {10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0, 10.0};

    angles(vector<double>(sides1, sides1 + 3));
    angles(vector<double>(sides2, sides2 + 9));
    angles(vector<double>(sides3, sides3 + 11));

    return 0;
}