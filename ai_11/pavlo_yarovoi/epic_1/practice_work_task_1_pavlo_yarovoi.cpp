#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    float a;
    int p;
    float r;
    float n;
    int t;

    printf("Enter amount of investments: ");
    scanf("%d", &p);
    printf("Enter investments duration: ");
    scanf("%d", &t);
    printf("Enter number of pays per year (1,3,12): ");
    scanf("%f", &n);
    printf("Enter annual comission(in percent): ");
    scanf("%f", &r);

    if (n==3 || n==12 || n==1) {
        a = p*(pow((r/100.0)/n+1, n*t));
        printf("Total amound of deposite: %.2f", a);
    } else {
        return 0;
    }
    return 0;
}