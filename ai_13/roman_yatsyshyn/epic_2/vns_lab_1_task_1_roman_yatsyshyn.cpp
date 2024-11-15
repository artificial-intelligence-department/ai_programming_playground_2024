#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    const double a = 100.0;
    const double b = 0.001;
    double c = 0;
    double d = 0;
    double e = 0;
    double result = 0;
    int choice_1 = 0;

    cout << "Choose type of data: \"1\" for double or \"2\" for float\n";
    cin >> choice_1;

    switch (choice_1)
    {
    case 1:
        c = pow(a-b, 4.0);
        d = pow(a, 4.0) - 4.0 * pow(a, 3.0) * b;
        e = 6.0*pow(a, 2.0)*pow(b, 2.0) - 4.0*a*pow(b, 3.0) + pow(b, 4.0);
        result = double((c-d)/e);
        cout << result;
        break;
    case 2:
        float c = pow((float)a-(float)b, 4.0f);
        float d = pow((float)a, 4.0f) - 4.0f * pow((float)a, 3.0f) * (float)b;
        float e = 6.0f*pow((float)a, 2.0f)*pow((float)b, 2.0f) - 4.0f*(float)a*pow((float)b, 3.0f) + pow((float)b, 4.0f);
        float result = ((float)c-(float)d)/(float)e;
        cout << result;
    }

}