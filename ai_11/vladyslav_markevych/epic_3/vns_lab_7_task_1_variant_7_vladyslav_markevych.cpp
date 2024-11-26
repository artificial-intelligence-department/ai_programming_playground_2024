#include <iostream>
#include <limits>

using namespace std;

int min(int a, int b, int c, int d, int e) {
    int minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    if (d < minValue) minValue = d;
    if (e < minValue) minValue = e;
    return minValue;
}
int min(int a, int b, int c, int d, int e, int f, int g) {
    int minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    if (d < minValue) minValue = d;
    if (e < minValue) minValue = e;
    if (f < minValue) minValue = f;
    if (g < minValue) minValue = g;
    return minValue;
}

int min(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    int minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    if (d < minValue) minValue = d;
    if (e < minValue) minValue = e;
    if (f < minValue) minValue = f;
    if (g < minValue) minValue = g;
    if (h < minValue) minValue = h;
    if (i < minValue) minValue = i;
    if (j < minValue) minValue = j;
    if (k < minValue) minValue = k;
    if (l < minValue) minValue = l;
    return minValue;
}

double min(double a, double b, double c, double d, double e) {
    double minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    if (d < minValue) minValue = d;
    if (e < minValue) minValue = e;
    return minValue;
}

double min(double a, double b, double c, double d, double e, double f, double g) {
    double minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    if (d < minValue) minValue = d;
    if (e < minValue) minValue = e;
    if (f < minValue) minValue = f;
    if (g < minValue) minValue = g;
    return minValue;
}

double min(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l) {
    double minValue = a;
    if (b < minValue) minValue = b;
    if (c < minValue) minValue = c;
    if (d < minValue) minValue = d;
    if (e < minValue) minValue = e;
    if (f < minValue) minValue = f;
    if (g < minValue) minValue = g;
    if (h < minValue) minValue = h;
    if (i < minValue) minValue = i;
    if (j < minValue) minValue = j;
    if (k < minValue) minValue = k;
    if (l < minValue) minValue = l;
    return minValue;
}

int main() {
    cout << "Мінімальне серед 5 значень типу int: " << min(20, 15, 30, 5, 10) << endl;
    cout << "Мінімальне серед 7 значень типу int: " << min(25, 18, 12, 6, 9, 3, 1) << endl;
    cout << "Мінімальне серед 12 значень типу int: " << min(35, 20, 15, 10, 5, 25, 30, 40, 45, 50, 55, 2) << endl;

    cout << "Мінімальне серед 5 значень типу double: " << min(12.5, 8.3, 5.6, 9.1, 3.7) <<endl;
    cout << "Мінімальне серед 7 значень типу double: " << min(18.4, 10.3, 6.9, 14.5, 7.2, 2.8, 4.4) << endl;
    cout << "Мінімальне серед 12 значень типу double: " << min(22.2, 17.7, 19.1, 10.5, 3.3, 8.8, 14.1, 7.9, 6.0, 5.5, 4.1, 1.2) << endl;

    return 0;
}
