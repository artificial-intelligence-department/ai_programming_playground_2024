#include <iostream>
#include <iomanip>
using namespace std;

/*
Формула обчислення складних відсотків за депозитом:
A = P * (1+(r/n))**(n*t)
Де:
A = Майбутня загальна сума інвестиції, включаючи відсотки
P = Основна сума інвестиції
r = річна процентна ставка (у десятковій формі, тобто 5% = 0,05)
n = кількість нарахувань відсотків на рік
t = час, на який гроші інвестуються, у роках
*/

double pow(double x, long long y) {
    double res = 1;
    for (int i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

int main() {
    long long n, t;
    double P, r;
    cout << \
    "The formula for calculating compound interest on a deposit:" << endl << \
    "A = P * (1+(r/n))**(n*t)" << endl << \
    "Where:" << endl << \
    "A = Future total investment amount, including interest" << endl << \
    "P = Principal of the investment" << endl << \
    "r = annual interest rate (in decimal form, i.e. 5% = 0.05)" << endl << \
    "n = number of interest accruals per year" << endl << \
    "t = time for which the money is invested, in years" << endl;
    cout << "Enter P, r, n, t in that order: ";
    cin >> P >> r >> n >> t;
    double A = P * pow((1+(r/n)),(n*t));
    cout << "A = " << fixed << setprecision(2) << A << endl;
}