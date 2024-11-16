#include <stdio.h>
#include <math.h>

int main() {
    double endsum;
    int sum;
    double percent;
    int percentkolvo;
    int time;
    double earn;

    printf("Enter Sum of deposit: ");
    scanf("%d", &sum);
     
    printf("Enter year percent: ");
    scanf("%lf", &percent);
    
    printf("Enter times of counting percent by year\n(1 = one time in year, 2 = per half year, 3 = every quartal): ");
    scanf("%d", &percentkolvo);
    
    printf("Enter time for which you want to deposit funds (in years): ");
    scanf("%d", &time);

    // Правильне приведення річного відсотка.
    percent = percent / 100;

    // Формула для складних відсотків.
    endsum = (long double)(sum * pow((1 + (percent / percentkolvo)), percentkolvo * time));
    earn = endsum - sum;

    // Виведення результату з двома знаками після коми
    printf("Sum after deposit: %.2Lf\n", endsum);
    printf("Earnings: %.2LF\n", earn);

    return 0;
}
