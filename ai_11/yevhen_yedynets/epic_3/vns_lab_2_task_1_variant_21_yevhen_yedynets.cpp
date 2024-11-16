#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int n = 13;
    double sum = 0.0;
    double fact = 1.0;

    for (int i = 1; i <= 13; ++i){
        fact *= i;
        double value = log(fact) / (i * i);
        sum += value;
    }

    cout<< "Сума перших 13 членів ряду: " << sum;

    return 0;
}