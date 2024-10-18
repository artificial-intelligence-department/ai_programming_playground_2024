#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <cmath>

// A = Майбутня загальна сума інвестиції, включаючи відсотки
// P = Основна сума інвестиції
// r = річна процентна ставка (у десятковій формі, тобто 5% = 0,05)
// n = кількість нарахувань відсотків на рік
// t = час, на який гроші інвестуються, у роках

int main(){

    double P;
    double r;
    double t;

    double option_month;
    double option_quarter;
    double option_year;

    printf("Введіть основну суму інвестиції: ");
    scanf("%lf", &P);
    // printf("Основна сума інвестиції = %lf\n",P);

    printf("Введіть річну процентну ставку (у вигляді десяткового дробу): ");
    scanf("%lf", &r);
    // 

    printf("Введіть час, на який гроші інвестуються (у роках): ");
    scanf("%lf", &t);
    // 

 
    option_month = P*pow(double(1+(r/12.0)), double(12.0*t));
    option_quarter = P*pow(double(1+(r/4.0)), double(4.0*t));
    option_year = P*pow(double(1+r), double(t));

    printf("Основна сума інвестиції = %.0lf\n",P);
    printf("Річна процентна ставка = %.3lf\n",r);
    printf("Час у роках = %.0lf\n",t);
    printf("Майбутня загальна сума інвестиції в разі щомісних нарахувань відсотків = %.3lf\n...в разі щоквартальних нарахувань = %.3lf\n...в разі щорічних нарахувань = %.3lf", option_month, option_quarter, option_year);

    return 0;
}