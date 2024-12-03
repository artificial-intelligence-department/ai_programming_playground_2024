#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std; 

int function_1() {
    float a, b;
    int c, d, e;
    double f;

    double array[6] = {a, b, c, d, e, f};

    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    sort(array, array+6);


    double sumMax = array[3]+array[4]+array[5];
    double sumMin = array[0]+array[1]+array[2];
    double result;
    if (sumMax > sumMin*2) {
        result = sumMax*sumMin;

    }
    else if (sumMax > sumMin*3) {
        result = sumMax/sumMin;
    }
    else if (sumMax > sumMin*4) {
        result = sumMax + sumMin;
    }
    cout << result;
    
    
    return result/76;
} 

int function_2(double &x) {
    int matrix[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = function_1();
        }   
    }

    int random = 1 + (rand() % 100);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j]+76+j-i)*random;
        }   
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j];
        }   
    }
    return matrix[5][5];
} 

int main() {
    double x = function_1();
    function_2(x);
    return 0;

}
