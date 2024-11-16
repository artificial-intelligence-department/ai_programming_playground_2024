#include <iostream>
#include <cmath>
using namespace std;

//уводимо допустиму похибку для нецілих чисел
const double EPSILON = 1e-9;

//функція для перевірки на ортогональність
bool Orthonormal(double a[][3]){
    //перевіряємо чи добуток рядка самого на себе рівний 1
    int n = sizeof(a[0])/sizeof(a[0][0]);
    for(int i = 0; i < n; i++){
        double same_multiply = 0.0;
        for(int j =0; j < n; j++){
            same_multiply += a[j][i]*a[j][i];
        }
        if ((same_multiply - 1.0)> EPSILON){
            return false;
        }
    }

    //перевіряємо чи добуток рядків рівний 0
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double different_multiply = 0.0;
            for(int k = 0; k < n; k++){
                different_multiply += a[k][i]*a[k][j];
            }
            if (abs(different_multiply)> EPSILON){
                return false;
            }
        }
    }

    return true;
}

int main(){
    //створюємо матрицю 3х3
    double matrix[3][3]{
        {1 / sqrt(2), 1 / sqrt(2), 0},
        {-1 / sqrt(2), 1 / sqrt(2), 0},
        {0, 0, 1}
    };
    
    //перевіряємо отримане значення з функції
    if(Orthonormal(matrix)){
        cout << "Matrix is orthonormal";
    }
    else{
        cout << "Matrix isn`t orthonormal";
    }
    return 0;
}