#include <iostream>
#include <math.h>

using namespace std;

double calculateHeight(double a, double b, double c) {
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return (2 * area) / a;
}

int main() {
    double a[5] = {3, 5, 6, 7, 9};
    double b[5] = {4, 12, 8, 24, 12};
    double c[5] = {5, 13, 10, 25, 15};

    double maxHeight = 0;
    int maxIndex = -1;

    for (int i = 0; i < 5; i++) {
        double height = calculateHeight(a[i], b[i], c[i]);
        cout << "Трикутник " << i + 1 << " зі сторонами (" << a[i] << ", " << b[i] << ", " << c[i] << ") має висоту h = " << height << endl;

        if (height > maxHeight) {
            maxHeight = height;
            maxIndex = i;
        }
    }

    cout << "Максимальна висота h = " << maxHeight << " у трикутника зі сторонами (" << a[maxIndex] << ", " << b[maxIndex] << ", " << c[maxIndex] << ")" << endl;

    return 0;
}
