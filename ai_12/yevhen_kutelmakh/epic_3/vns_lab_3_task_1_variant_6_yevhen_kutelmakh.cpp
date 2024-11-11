/*
y = e^(x*cos(Pi/4)) * cos(x*sin(Pi/4))
S = 1 + cos(Pi/4)*x/!1 + ... + cos(n(Pi/4))*(x^n)/!n, звідси:
a(n) = cos(n(Pi/4))*(x^n)/!n
У нашому випадку цей член доцільніше представити, як:
a(n) = cos(n(Pi/4)) * ((x^n)/!n), і нехай 
b(n) = cos(n(Pi/4)), і будемо його обчислювати безпосередньо, а
c(n) = ((x^n)/!n), і його будемо обчислювати рекурентно:
с(n)/c(n-1) = (x^n * (n-1)!) / (n! * x^(n-1)) = x / n, тобто:
с(n) = c(n-1) * (x / n)
*/
#include <iostream>
#include <cmath>
using namespace std;

const double Pi = 3.141592653589793;
const double epsilon = 0.0001;

double calculateFunction(double x) {
    return exp(x * cos(Pi / 4)) * cos(x * sin(Pi / 4));
}

double calculateCn(double x, int n) {
    if (n == 0)
        return 1;
    return calculateCn(x, n - 1) * (x / n);
}

double calculateSn(double x, int n) {
    double b = cos(n * Pi / 4);
    double c = calculateCn(x, n);
    return b * c;
}

int main() {
    double a = 0.1;
    double b = 1.0;
    int k = 10;
    double step = (b - a) / k;

    for (double x = a; x <= b; x += step) {
        double SN = 1;
        double SE = 1;
        double se;
        double sn;
        for (int i = 1; i <= 25; i++) {
            sn = calculateSn(x, i);
            SN += sn;
        }
        int i = 1;
        while (true) {
            se = calculateSn(x, i);
            if (se < epsilon) break;
            SE += se;
            i++;
        }
        cout << "X = " << x << "   \tSN = " << SN << "\tSE = " << SE << "\tY = " << calculateFunction(x) << "\n";
    }
    return 0;
}
