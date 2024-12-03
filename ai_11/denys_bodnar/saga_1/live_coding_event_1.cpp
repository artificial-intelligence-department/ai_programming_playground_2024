#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int Variant = 2;

double function_1 () {
    float a, b;
    int c, d, e;
    double f;

    cout << "Введіть два цілих числа (a і b): " << endl;
    cin >> a >> b;
    cout << "Введіть три цілих числа (c, d, e): " << endl;
    cin >> c >> d >> e;
    cout << "Введіть одне дійсне число з двійковою точністю (f): " << endl;
    cin >> f;

    double arr[] = {static_cast<double>(a), static_cast<double>(b), static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};
    sort(arr, arr + 6);

    double maxSuma = arr[3] + arr[4] + arr[5];
    double minSuma = arr[0] + arr[1] + arr[2];

    double result;

    if (maxSuma > minSuma * 2) {
        result = maxSuma * minSuma;
    } else if (maxSuma > minSuma * 3) {
        result = maxSuma / minSuma;
    } else if (maxSuma > minSuma * 4) {
        result = maxSuma + minSuma;
    }

    double x = result / Variant;
    
    return x;
}

double function_2(double &x, double matrix [5][5]) {

    srand(static_cast<unsigned>(time(0)));

    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            matrix[a][b] = x;
        }
    }

    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            matrix [a][b] = (matrix [a][b] + Variant + a - b) * (rand() % 100 +1);
        }
    }
    cout << "Matrix: " << endl;
    for (int a = 0; a < 5; a++){
        for (int b = 0; b < 5; b++){
            cout << matrix[a][b] << "\t";
        }
        cout << endl;
    }

}



int main (){
    
    cout << "Результат обчислення (function_1):\n " << function_1() << endl;
    double x = function_1();
    double matrix [5][5];
    function_2(x, matrix);

    return 0;
}