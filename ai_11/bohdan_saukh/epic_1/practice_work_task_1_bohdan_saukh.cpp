#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    float a;
    int p;
    float r;
    float n;
    int t;

    printf("Введіть суму інвестиції: ");
    scanf("%d", &p);
    printf("Введіть час інвестиції: ");
    scanf("%d", &t);
    printf("Введіть кількість нарахувань відсотків на рік (1,3,12): ");
    scanf("%f", &n);
    printf("Введіть відсоткоу ставку(в %): ");
    scanf("%f", &r);

    if (n==3 || n==12 || n==1) {
        a = p*(pow((r/100.0)/n+1, n*t));
        printf("Загальна сума депозиту: %.2f", a);
    } else {
        return 0;
    }
    return 0;
}