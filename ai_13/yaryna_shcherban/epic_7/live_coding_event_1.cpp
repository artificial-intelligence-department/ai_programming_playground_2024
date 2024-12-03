#include <iostream>
#include <algorithm>

using namespace std;
//Цілочисельна константа
const int Variant = 84;

double function_1(){
//Дійсна змінна
    float a, b;
//Цілочисельна змінна
    int c, d, e;
//З подвійною точністю 
    double f;
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

//Двовимірний масив
void function_2 ( double &x, double matrix[5][5]) {
    for (int i = 0; i < 5; i++) {
        for ( int j = 0; j < 5; j++){
            matrix[i][j] = x;
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

int main (){

    double x = function_1();
    double matrix[5][5];
    function_2(x, matrix);



    return 0;
}