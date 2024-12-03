#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <iostream>      // варіант 4
#include <algorithm>
#include <cstdlib>

const int INF = INT32_MAX;
const int VARIANT = 82;

double function_1(){
    float a, b; 
    std::cin >> a >> b;
    int c, d, e;
    std::cin >> c >> d >> e;
    double f;
    std::cin >> f;
    double arr[6] = {a, b, c, d, e, f};
    double* arr1 = new double [6];
    arr1[0] = arr[0];
    arr1[1] = arr[1];
    arr1[2] = arr[2];
    arr1[3] = arr[3];
    arr1[4] = arr[4];
    arr1[5] = arr[5];
    std::sort(arr1, arr1 +6);
    double res;
    std::cout << "Max values: " << arr1[3] << "  " << arr1[4] << "  " << arr1[5] << std::endl;
    std::cout << "Min values: " << arr1[0] << "  " <<  arr1[1] << " " << arr1[2] << std::endl;
    if(arr1[5] + arr1[4] > (arr1[0] + arr1[1] ) * 4){
        res = (arr1[5] + arr1[4]) + (arr1[0] + arr1[1]);
        std::cout << (arr1[5] + arr1[4]) + (arr1[0] + arr1[1]) << std::endl;
    } 
    else if(arr1[5] + arr1[4] > (arr1[0] + arr1[1] ) * 3){
        res = (arr1[5] + arr1[4]) / (arr1[0] + arr1[1]);
        std::cout << (arr1[5] + arr1[4]) / (arr1[0] + arr1[1]) << std::endl;
    } 
    else if(arr1[5] + arr1[4] > (arr1[0] + arr1[1] ) * 2){
        res = (arr1[5] + arr1[4]) + (arr1[0] + arr1[1]);
        std::cout << (arr1[5] + arr1[4]) * (arr1[0] + arr1[1]) << std::endl;
    } 
    double X = VARIANT / res;
    std::cout << X << std::endl;
    return X;
}

double** function_2(double& x){
    double** arr = new double*[5];
    for(int i = 0; i < 5; i++){
        arr[i] = new double[5];
        for(int j = 0; j < 5 ; j++){
            arr[i][j] = x;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 ; j++){
            arr[i][j] = (x +VARIANT + i + j) * (std::rand() % 100 + 1);
        }
    }

    for(int i = 0; i < 5; i++){
        std::cout << std::endl;
        for(int j = 0; j < 5 ; j++){
            std::cout << arr[i][j] << "  ";
        }
    }
    return arr;
}

double* function_3(double** tower){
    double* arr = new double[5];
    for(int i = 0; i < 5; i++){
        double min = tower[i][0];
        for(int j = 0; j < 5; j++){
                if(min > tower[i][j]) min = tower[i][j];
        }
        arr[i] = min;
    }
    std::sort(tower[0], tower[0] + 5);
    std::sort(tower[1], tower[1] + 5);
    std::sort(tower[2], tower[2] + 5);
    std::sort(tower[3], tower[3] + 5);
    std::sort(tower[4], tower[4] + 5);
    double* arr2 = new double[5];
    arr2[0] = tower[0][0];
    arr2[1] = tower[1][0];
    arr2[2] = tower[2][0];
    arr2[3] = tower[3][0];
    arr2[4] = tower[4][0];
    for(int i = 0; i < 5; i++){
        std:: cout << "arr1 : " << arr[i] << "\tarr2 : " << arr2[i] << std::endl;
    }
    return arr2;
}


int main(){
    double x = function_1();
    double** tower = function_2(x); 
    double* bebe = function_3(tower);
    return 0;
}