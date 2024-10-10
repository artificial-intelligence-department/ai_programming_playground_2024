#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main (){

    int n, t;
    double P, A;
    float r;

    printf("What is the investment amount? ");
    scanf("%lf", &P);

    printf("At what interest rate? ( decimal fraction) ");
    scanf("%f", &r);

    printf("Number of accruals per year (1, 4 or 12) ");
    scanf("%d", &n);

    printf("For how many years? ");
    scanf("%d", &t);

    A = P * pow (( 1 + r/n ), (n * t));

    printf ("Money invested : %.2f\n", P);
    printf ("Interest rate : %.2f%%\n", (r*100));
    printf ("Number of accruals per year : %d\n ", n);
    printf ("Number of years : %d\n ", t);
    printf ("Total amount : %.4lf\n ", A);
    printf ("Clear profit :  %.4f\n ", A - P);

    return 0;
}

//A = Майбутня загальна сума інвестиції, включаючи відсотки
//P = Основна сума інвестиції
//r = річна процентна ставка (у десятковій формі, тобто 5% = 0,05)
//n = кількість нарахувань відсотків на рік
//t = час, на який гроші інвестуються, у роках
