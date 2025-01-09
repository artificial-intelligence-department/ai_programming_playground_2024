#include <iostream>

using namespace std;



int main() {
    float a, b, c, price;

    cout << "Введіть початкові дані(см): " << endl;
    cin >> a >> b >> c;



    double V = a*b*c;
    cout << "Об'єм: " << V << " см.куб" << endl;

    float p = 0;
    float* ptr = &p;//використано вказівники
    float o = 0;
    float k = 0;

    cout << "Скільки коштували помідори(грн): ";
    cin >> *ptr;
    cout << "Скільки коштували огірки(грн): ";
    cin >> o;
    cout << "Скільки коштували кріп(грн): ";
    cin >> k;        

    price = p + o + k;
    cout << "Покупка коштувала: " << price;

    return 0;
}