// 8 variant y = xsin(pi/4)/(1 - 2xcos(pi/4) + x**2); S = (x**n)*sin(n*(pi/4))
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {

    float a = 0.1;
    float b = 0.8;
    short k = 10;
    float step = (b-a)/k;
    vector<double> x(k + 1);
    vector<double> y;
    for(int i = 0; i <= k; i++){    //створюємо масив зі значеннями х для кожного х з кроком
        x[i] = a + step*i;
    }
    for(double num : x) {
        double res = (num * sin(M_PI/4))/(1 - 2 * num * cos(M_PI/4) + pow(num,2));      //обраховуємо значення функції за кожного х
        y.push_back(res); 
    }
    vector<double> trow;    //ствоємо масив з рядом Тейлора
    short n = 40;
    for(double num : x) {
        double sum = 0;
        for(int i = 1; i <= n; i++) {
            double tmp = pow(num,i) * sin(i* M_PI / 4);
            sum += tmp;
        }
        trow.push_back(sum);
    }

    vector<double> erow;    //створюємо масив з точністю до епсилона
    for(double num : x) {
        double sum = 0;
        int i = 1;
        double tmp = 1;
        while(tmp > 0.0001) {
            tmp = pow(num,i) * sin(i* M_PI / 4);
            sum += tmp;
            i++;
        }
        erow.push_back(sum);
    }

    printf("Function row: ");
    for(double res : y) {
        printf("%.4lf ", res);
    }

    printf("\nTailor's row: ");
    for(double res : trow) {
        printf("%.4lf ", res);
    }

    printf("\nEpsilon row: ");
    for(double res : erow) {
        printf("%.4lf ", res);
    }

    return 0;
}