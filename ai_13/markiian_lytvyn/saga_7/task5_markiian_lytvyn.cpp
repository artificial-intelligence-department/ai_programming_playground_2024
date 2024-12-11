#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a, b, c, r;
    cin >> a >> b >> c >> r;
    double p = (a+b+c)/2;
    double R1 = (a*b*c)/(4*sqrt(p * (p - a) * (p - b) * (p - c)));
    double R2 = (sqrt(p * (p - a) * (p - b) * (p - c)))/p;
    char answer1, answer2;
    if (r >= R1) {
        answer1 = '+';
    } 
    else {
        answer1 = '-';
    }
    if (r <= R2) {
        answer2 = '+';
    } 
    else {
        answer2 = '-';
    }
    cout << answer1 << answer2;
}
