#include <iostream>

using namespace std;

const int var = 12;

double functiun_1 (double x) {
    float a, b;
    int c, d, e;
    double f;

    cin >> a >> b >> c >> d >> e >> f;
    
    double max1, max2, max3, min1, min2, min3;

    max1 = 0

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
    
    double x = result/(double)var;

    return x;
}

double function_2 (double& x) {
    double** matrix = new double* [5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (x + var + j - i);
        }
    }
    
    
    
    return matrix;
}




int main () {
    double x = 0;
    functiun_1(x);
    
    
    
    
    
    
    
    
    
    return 0;
}