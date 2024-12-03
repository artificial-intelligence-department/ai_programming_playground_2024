#include <iostream>
#include <algorithm>

using namespace std;
//Цілочисельна константа
const int Variant = 84;
const int MAX = 100;

double function_1(){
//Дійсна змінна
    float a, b;
//Цілочисельна змінна
    int c, d, e;
//З подвійною точністю 
    double f;
//Оператори виведення та введення
    cout << "Enter a, b (float) : " << endl;
    cin >> a >> b;
    cout << "Enter c, d, e (int) : " << endl;
    cin >> c >> d >> e;
    cout << "Enter f (double) : " << endl;
    cin >> f;
//Одновимірний масив
    double array_1[6];
        array_1[0] = a;
        array_1[1] = b;
        array_1[2] = c;
        array_1[3] = d;
        array_1[4] = e;
        array_1[5] = f;
    int n = sizeof(array_1) / sizeof(array_1[0]);
    sort(array_1, array_1 + n);
//Цикл for
    for (int i; i < 3; i++) { //Для пошуку найменших
        cout << array_1[i] << " " << endl;
    }
    for (int i = n - 3; i < n ; i++) {  // Для пошуку найбільших
        cout << array_1[i] << " " << endl;
    }

    double sum_max = array_1[5] + array_1[4] + array_1[3];
    double sum_min = array_1[0] + array_1[1] + array_1[2];
    double sum;
//Оператор if та розгалуження
    if ( sum_max > (sum_min * 2) ) {
        sum = sum_max * sum_min;
    } else if ( sum_max > (sum_min * 3) ) {
        sum = sum_max / sum_min;
    } else if ( sum_max > (sum_min * 4) ) {
        sum = sum_max + sum_min;
    }

    double x = sum / Variant;
    cout << "First task : " << function_1 << endl;
    return x;
}

//Двовимірний масив , параметри та аргументи функції 
void function_2 ( double &x_1, double matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for ( int j = 0; j < 5; j++){
            matrix[i][j] = x_1;
        }
    }
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < 5; i++) {
        for ( int j = 0; j < 5; j++){
            matrix[i][j] = (matrix[i][j] + Variant + (j - i)) * (rand() % 100 + 1);
        }
    }

    cout << "Array  \n";
    for (int i = 0; i < sizeof(matrix); ++i) {
        for (int j = 0; j < 5; j++ ) {
            cout << matrix[i][j] << " ";
        }
    }
    cout << endl;

}

void function_3 ( double matrix[5][5], double tower[5], int n, int m) {
       cout << " { ";
    for (int i = 0; i < n; i++) {
        int minm = matrix[i][0];
        for (int j = 1; j < m; j++) {
 
            if (matrix[i][j] < minm) {
                minm = matrix[i][j];
            }
        }
        cout << minm << ", ";
    }
        cout << "}";
    
    void smallestInRow(int matrix[][MAX], int n, int m) {
        cout << " { ";
        for (int i = 0; i < n; i++) {
 
            int minm = mat[i][0];
 
            for (int j = 1; j < m; j++) {
                if (mat[i][j] < minm)
                    minm = mat[i][j];
            }
            cout << minm << ", ";
        }
        cout << "}";
    }
    void smallestInCol(int matrix[][MAX], int n, int m) {
        cout << " { ";
        for (int i = 0; i < m; i++) {
            int minm = matrix[0][i];
        for (int j = 1; j < n; j++) {
            if (matrix[j][i] < minm)
                minm = matrix[j][i];
        }
        cout << minm << ", ";
        }
        cout << "}";
    }
}


int main (){
    int n, m;
    double x = function_1();
    double x_1 = x;
    double matrix[5][5];
    function_2(x_1, matrix);

    double tower[5];
    function_3(matrix, tower, n, m);
        cout << "Minimum element of each row is ";
        smallestInRow(matrix, n, m);
 
        cout << "\nMinimum element of each column is ";
        smallestInCol(matrix, n, m);

    return 0;
}