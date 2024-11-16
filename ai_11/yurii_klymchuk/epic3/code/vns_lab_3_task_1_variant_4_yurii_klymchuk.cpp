#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double a = 0.1, b = 0.8, k = 10.0, e = 0.0001;
const int n = 10;

//Функція для обрахунку ряду Тейлор Макклорена з 10 елементів
double S_of_N(double x){
    double sum = 0;
    for (int i = 1; i <= n; i++){
        sum += pow(-1, i+1)*(pow(x, 2*i)/(2*i*(2*i-1)));
    }
    return sum;
};

//Функція для обрахунку ряду Тейлор Макклорена з точністю 0.0001
double S_of_E(double x){
    double sum = 0.0;
    double previous = 0.0;
    int i = 1;
    do{
        previous = sum;
        sum += pow(-1, i+1)*(pow(x, 2*i)/(2*i*(2*i-1)));
        i++;
    }while (abs(sum-previous) > e);
    return sum;
};


//Функція для обрахунку значення функції від х
double f_of_x(double x){
    return x*atan(x)-log(sqrt(1+x*x));
}

int main() {
    double step = (b - a) / k;//змінна для кроку значення х
    
    //Вивід обрахунків для всіх значень х в заданому діапазоні із заданим кроком
    for (double x = a; x <= b; x += step) {
        cout << "x = " << setprecision(2) << x << "\nusing n = " << n << " sum is "<< setprecision(10) << S_of_N(x) << endl;
        cout << "using e = " << e << " sum is "<< setprecision(10) << S_of_E(x) << endl;
        cout << "using f(x) = x*arctg(x) - sqrt(1 + x^2) = " << setprecision(10) << f_of_x(x) << "\n\n";
    }
    return 0;
}