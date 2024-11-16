#include <iostream>//Підключення бібліотек
#include "stdio.h"
#include <cmath>

using namespace std;//використання простору імен std

int main(){//головна функція
    float p, t, A;//змінні типу float
    float r = 0.05;
    float n = 0.01;
    printf("Enter amount of money you want to put: ");//вивід повідомлення на екран
    scanf("%f",&p);//ввід даних в консолі
    printf("How many years: ");//вивід повідомлення на екран
    scanf("%f",&t);//вивід повідомлення на екран; %f - для чисел типу float
    A = p * pow(1+r/n,n*t);//присвоєння змінній А значення виразу - p * pow(1+r/n,n*t)
    printf("Sum: %.2f $\n", A);//вивід повідомлення на екран; %.2f - для чисел типу float з двома знками після коми 
    printf("Profit: %.2f $\n", A-p);//вивід повідомлення на екран
}