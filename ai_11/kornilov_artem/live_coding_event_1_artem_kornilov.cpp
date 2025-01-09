#include <iostream>
#include <algorithm>

using namespace std;

const int var = 12;

double function_1 (double x) {
    float a, b;
    int c, d, e;
    double f;

    cin >> a >> b >> c >> d >> e >> f;
    
    double max1, max2, max3, min1, min2, min3;

    max1 = -99999999;
    max2 = -99999999;
    max3 = -99999999;
    min1 = 99999999;
    min2 = 99999999;
    min3 = 99999999;

    double numbers[6] = {a, b, c, d, e, f};

    for (int i = 0; i < 6; i++) {
        if (max1 < numbers[i]) {
            max1 = numbers[i];
        }

        if (min1 > numbers[i]) {
            min1 = numbers[i];
        }

    }

    for (int i = 0; i < 6; i++) {
        if (max2 < numbers[i] && numbers[i] < max1) {
            max2 = numbers[i];
        }

        if (min2 > numbers[i] && numbers[i] > min1) {
            min2 = numbers[i];
        }
    }

    for (int i = 0; i < 6; i++) {
        if (max3 < numbers[i] && numbers[i] < max1 && numbers[i] < max2) {
            max3 = numbers[i];
        }

        if (min3 > numbers[i] && numbers[i] > min1 && numbers[i] > min2) {
            min3 = numbers[i];
        }
    }

    double sumMax = max1 +  max2 + max3;
    double sumMin = min1 + min2+ min3;
    double result;
    
    if (sumMax > sumMin*2) {
        result = sumMax*sumMin;
    }

    if (sumMax > sumMin*3) {
        result = sumMax/sumMin;
    }

    if (sumMax > sumMin*4) {
        result = sumMax + sumMin;
    }
    
    x = result/(double)var;

    return x;
}

void function_2 (double& x, double arr[][5]) {
    double** matrix = new double* [5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (x + var + j - i)*(1 + rand() % 9);
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = matrix[i][j];
        }
    }
}




int main () {
    double x = 0;
    function_1(x);
    double tower[5][5];
    function_2(x, tower);
    double ass[5][5];
    
    
    
    
    
    
    return 0;
}