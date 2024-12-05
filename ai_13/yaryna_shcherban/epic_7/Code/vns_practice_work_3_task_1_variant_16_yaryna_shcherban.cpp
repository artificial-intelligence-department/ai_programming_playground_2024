#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main (){

    double P, A, profit;
    int t;
    float r;

    cout << "What is the investment amount? ";
    cin >> P;
    cout << "For how many days? ";
    cin >> t;
    cout << "At what interest rate? ";
    cin >> r;

    r /= 100;
    profit = P * (r/365) * t;
    A = P + profit;

    cout << "Clear profit " << profit << endl;
    cout << "Total amount : " << A << endl;

    return 0;
}