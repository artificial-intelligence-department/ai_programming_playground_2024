#include <bits/stdc++.h>
using namespace std;

double funceps (float x){
    double sum = 0.0;
    double temp;
    int i = 0;
    do {
        temp = (1.0 / (2 * i + 1)) * pow((x - 1) / (x + 1), 2 * i + 1);
        sum += temp;
        ++i;
    } while (abs(temp) > 0.0001);
    return sum;
}
double func (float x, int n){
    double s = 0.0;
    for (int i = 0; i < n; i++){
        s += (1.0 / (2 * i + 1)) * pow (((x - 1) / (x + 1)), (2 * i + 1));
    }
    return s;
}


int main() {
    for (float i = 0.2; i <= 1; i += 0.08){
        cout << i << "\t" << 0.5 * log(i) << "\t" << func(i, 10) << "\t" << funceps(i) << "\t" << endl;
    }
    return 0;
}
