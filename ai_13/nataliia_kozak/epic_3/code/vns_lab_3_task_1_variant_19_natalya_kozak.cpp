#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    float e = 0.0001, a = 0.1;
    int b = 1, k = 10;
    double SN = 0, SE = 0, y;
    for(float x = a; x <= b; x+=(b-a)/k){
        double an = 1;
        SN = 0;
        SE = 0;
        for(int n = 1; n <= 20; n++){
            SN += an;
            an *= 2*x/n;
        }
        an = 1;
        int n = 1;
        while(an >= e){
            SE += an;
            an *= 2*x/n;
            n++;
        }
        y = exp(2*x);
        printf("\nX=%f SN=%f SE=%f Y=%f", x, SN, SE, y);
    }
    return 0;
}