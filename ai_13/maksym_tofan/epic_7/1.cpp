#include <iostream>
#include <algorithm>

using namespace std;

double function_1() {

double a, b, f;
int c, d, e;

cout << "Введи а: ";
cin >> a;
cout << "Введи b: ";
cin >> b;
cout << "Введи c: ";
cin >> c;
cout << "Введи d: ";
cin >> e;
cout << "Введи f: ";
cin >> f;

double values[6] = {a, b, static_cast<double>(c),static_cast<double>(d), static_cast<double>(e), f};

sort(values, values + 6);

double sum_min = values[0]  + values[1] + values[2];
double sum_max = values[3]  + values[4] + values[5];

double result = 0;

if (sum_max > sum_min * 4) {
result = sum_max + sum_min;
} else if (sum_max > sum_min * 3) {
    result = sum_max / sum_min;
} else if (sum_max > sum_min * 2) {
result = sum_max / sum_min;
}

int variant_number = 79;

result /= variant_number;

cout << "Результат: " << result << endl;

return result;

}


int main() {

function_1();
return 0;

}