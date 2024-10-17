// 18 варіант
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    int a = 1000;
    double b = 0.0001;
    int res;

    double act1 = pow((a - b), 3);
    double act2 = pow(a,3);
    double numerator = act1 - act2;
    cout << fixed << setprecision(5) << "Чисельник: " << numerator << endl;

    double act3 = pow(b,3);
    double act4 = 3 * a * pow(b,2);
    double act5 = 3 * b * pow(a,2);
    double denominator = act3 - act4 - act5;
    cout << "Знаменник: " << denominator << endl;

    double result = numerator/denominator;
    cout << "Відповідь: " <<  result;

    return 0;
}