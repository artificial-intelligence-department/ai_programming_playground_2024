#include <iostream>
#include <cmath>

using namespace std;



double factorial(int n) {
    if (n <= 1) {
    return 1;
    } else {
    return n * factorial(n - 1);
    }
}


int main() {

int n;
cin >> n;
int i;
double *result = new double[i];
double sum;

for(int i = 1; i <= n; i++){
    result[i] = pow(10, -i) * factorial(i-1);
    sum += result[i];

    if(result[i] <= 0.0001){
        sum -= result[i];
    cout << sum<< endl;
    break; 
    }
}

cout << sum;
delete[] result;
return 0;
}
