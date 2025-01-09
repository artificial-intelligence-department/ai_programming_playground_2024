#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

const int VAR = 8;

double function_1() {
    float a, b;
    int c, d, e;
    double f;

    cin >> a >> b;
    cin >> c >> d >> e;
    cin >> f;

    double values[6] = {a, b, c, d, e, f};

    sort(values, values + 6);

    double min1 = values[0], min2 = values[1], min3 = values[2];
    double max1 = values[3], max2 = values[4], max3 = values[5];

    double sum_max = max1 + max2 + max3;
    double sum_min = min1 + min2 + min3;

    double result;
    if (sum_max > sum_min * 4){
        result = sum_max + sum_min;
    }
    else if (sum_max > sum_min * 3){
        result = sum_max / sum_min;
    }
    else if (sum_max > sum_min * 2){
        result = sum_max * sum_min;
    }

    result /= VAR;
    cout << result;

    return result;
}

double **function_2(double &x){
    double **matrix = new double*[5];
    for (int i = 0; i < 5; i++){
        matrix[i] = new double[5];
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = {x};
        }
    }
    cout << endl;
    srand(time(0));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = (matrix[i][j] + VAR + j - i) * (rand() % 100 + 1);
            cout << matrix[i][j] << endl;
        }
    }

    return matrix;
}   

double *function_3(double **matrix){
    double array_1[5];
    double array_2[5];

    // 1 Спосіб
    for (int j = 0; j < 5; j++){
        array_1[j] = matrix[0][j];
        for (int i = 1; i < 5; i++){
            array_1[j] = min(array_1[j], matrix[i][j]);
        }
    }

    // 2 Спосіб
    for (int j = 0; j < 5; j++){
        double min = matrix[0][j];
        for (int i = 1; i < 5; i++){
            if (min > matrix[i][j]){
                min = matrix[i][j];
            }
        }
        array_2[j] = min;
    }

    for (int i = 0; i < 5; i++){
        if (array_1[i] != array_2[i]){
            cout << "Не співпадають!" << endl;
            return 0;
        }
    }
    cout << "Результати співпадають" << endl;

    return array_1;
}

 function_4(double *result){

struct Student{
    string firstName;
    string lastName;
    double money;
}

}

int main(){
    double x = function_1();

    double **matrix = function_2(x);

    double *result = function_3(matrix);

    function_4(result);

    return 0;
}