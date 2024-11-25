#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int l, w;
    cin >> l >> w;

    double operation = sqrt(pow(l, 2) + pow(w, 2));

    double result = round(operation * 100) / 100;

    cout << fixed << setprecision(2) << result << endl;
    return 0;
}