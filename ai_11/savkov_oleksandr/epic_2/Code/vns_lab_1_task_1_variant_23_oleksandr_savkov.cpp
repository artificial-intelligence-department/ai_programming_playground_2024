#include <iostream>
#include <cmath>
using namespace std;

int main(){
    float a = 1000;
    float b = 0.0001;
    float chys = pow(a+b, 3) - pow(a,3)+ (3 * b * pow(a,2));
    float znam = (3 * a* pow(b,2)) + pow(b,3);
    float resultFloat = chys/znam;
    cout << "Float result: " << resultFloat << endl;

    double a2 = 1000;
    double b2 = 0.0001;
    double chys2 = pow(a+b, 3) - pow(a,3)+ (3 * b * pow(a,2));
    double znam2 = (3 * a* pow(b,2)) + pow(b,3);
    double resultDouble = chys2/znam2;
    cout << "Double result: " << resultDouble << endl;

    return 0;
}