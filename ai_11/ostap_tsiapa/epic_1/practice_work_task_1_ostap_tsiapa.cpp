#include <stdio.h>
#include <math.h>

int main() {
    double suma, stavka, R;
    int n, t;
    
    printf("Основна сума інвестиції (suma): ");
    scanf("%lf", &suma);
    
    printf("Річна процентна ставка (у десятковій формі): ");
    scanf("%lf", &stavka);
    
    printf("Кількість нарахувань відсотків за рік (n): ");
    scanf("%d", &n);
    
    printf("Час, на який гроші інвестуються (у роках): ");
    scanf("%d", &t);
    
    R = suma * pow((1 + stavka/n), n*t);
    
    printf("Загальна сума прибутку разом з відсотками (R): %.2lf\n", R);
    printf("Сума заробітку: %.2lf\n", R - suma);
}
