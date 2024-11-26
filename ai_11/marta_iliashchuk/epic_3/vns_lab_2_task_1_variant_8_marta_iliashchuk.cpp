#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int n = 1;
    float epsilon = 0.0001;
    float a_n;
    float sum = 0;

    do {
        a_n = (2*n -1)/pow(2, n);
        sum+=a_n;
        n++;
    }while (abs(a_n)> epsilon);

    cout<<"Сума ряду: "<<fixed<<setprecision(4)<<sum;

    return 0;
}