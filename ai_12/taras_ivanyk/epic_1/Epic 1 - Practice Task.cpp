#include <iostream>
#include <stdio.h> // ця бібліотека дає змогу користуватись printf/scanf
#include <math.h>

int main(){
double P,r,A,t;// не ціле число
int n; // ціле число
double profit;

printf("Введіть суму депозиту (P)");
scanf("%lf", &P); // & вказує на місце пам'яті де це число зберігається

printf("Введіть річну процентну ставку (у десятковій формі, наприклад 0.05 для 5%)");
scanf("%lf", &r); 

printf("Введіть час в роках (t)");
scanf("%lf", &t);

printf("Виберіть кількість нарахувань відсотків на рік (1 - річні, 4 - щокварталу, 12 - щомісяця) ");
scanf("%d",&n);

A = P * pow(1+ r/n, n*t); // future sum of investment

profit = A - P;

printf("\n-----Результати-----\n");
printf("Початкова сума інвестиції = %.2lf\n", P);
printf("Річна процентна ставка = %.2lf%%\n", r*100);
printf("Загальна сума інвестиції (в майбутньому(A)) %.2lf\n", A);
printf("Прибуток= %.2lf\n", profit);

return 0;

}
