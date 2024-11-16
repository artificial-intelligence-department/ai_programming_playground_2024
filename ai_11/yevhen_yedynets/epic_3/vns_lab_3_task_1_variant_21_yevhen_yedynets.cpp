#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;

int main(){
    double a = 0.1;
    double b = 1.0;
    int n = 40;
    int k = 10;
    double epsilon = 0.0001;
    double step = (b - a) / k;

    for (double x = a; x <= b; x += step){
        double SN = 0.0;

        for (int i = 0; i < n; ++i){
            double value_1 = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
            SN += value_1;
        }

        double SE = 0.0;
        double value_2 = x;
        int i = 0;

        while (abs(value_2) >= epsilon){
            SE += value_2;
            i += 1;
            value_2 = pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
        }

        double y = atan(x);
        cout<< "X = " << x << "   SN = " << SN << "   SE = " << SE << "   Y = " << y << endl;
    }

    return 0;
}