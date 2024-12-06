#include <iostream>
#include <algorithm>
using namespace std;
const  int VARIANT = 76;

double function_1() {
    int c, d, e;
    double a, b, f;

    cout << "Enter 2 valid nums (a, b): ";
    cin >> a >> b;

    cout << "Enter 3 full nums (c, d , e):  ";
    cin >> c >> d >> e;

    cout << "Enter 1 double num(f): ";
    cin >> f;

    double nums[6];
    nums[0] = a;
    nums[1] = b;
    nums[2] = c;
    nums[3] = d;
    nums[4] = e;
    nums[5] = f;

    int n = sizeof(nums) / sizeof(nums[0]);
    sort(nums, nums + 6);


    double result = 0;
    //знаходження 3 найбільших елементів
    double sumMax = nums[5] + nums[4] + nums[3];
    //знаходження 3 найменших елементів
    double sumMin = nums[0] + nums[1] + nums[2];

    if (sumMax > sumMin * 2) {
        result = sumMax * sumMin;
    }
    else if (sumMax > sumMin * 3) {
        result = sumMax / sumMin;
    }
    else if (sumMax > sumMin * 4) {
        result = sumMax + sumMin;
    }

    result /= VARIANT;
    cout << "Result in function_1: " << result << endl;
    return result;
}

void function_2(double &x, double matrix[5][5]) {
    //заповнення матриці за значення x
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = x;
        }
    }
    //Оновлення матриці за формулою

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (matrix[i][j] + VARIANT + j - i) * (rand() % 100 + 1);
        }
    }
    //оновленя матриця за формулою(Виведення)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << "\t";
        }
    }
}

void function_3(double matrix[5][5], double arr[5]) {
    //Знаходження найменшого елемента матриці з стовпця
    double minCols;
    for(int j = 0; j < 5; j++) {
        minCols = matrix[0][j];
        for (int i = 1; i < 5; i++) {
            if (matrix[i][j] < minCols) {
                minCols = matrix[i][j];
            }
        }
        arr[j] = minCols;
    }
    
for(int j = 0; j < 5; j++) {
    cout << "The smallest values in each column: " << arr[j] << " " << endl;
}

}
int main() {
    double result_x = function_1();

    double x = result_x;
    double matrix[5][5];
    function_2(x, matrix);

    double arr[5];
    function_3(matrix, arr);
    return 0;
}