#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib> // для rand

using namespace std;

const int VARIANT = 25;

double function_1(){
    
    double a, b; //використана дійсна змінна
    double f; // число з подвійною точністю
    int c, d, e;

    cout << "Введіть два дійсних числа a, b: ";
    cin >> a >> b;

    cout << "Введіть три цілих числа c, d, e: ";
    cin >> c >> d >> e;

    cout << "Введіть одне число з подвійною точністю f";
    cin >> f;

    vector<double> numbers = {a, b, static_cast<double> (c), static_cast<double> (d), static_cast<double> (e), f};

    sort(numbers.begin(), numbers.end()); // за зростанням 

    cout << "Три найбільші числа: " << numbers[3] << numbers[4] << numbers[5] << endl;
    cout << "Три найменші числа: " << numbers[0] << numbers[1] << numbers[2] << endl;

    double sumLargest = numbers[3] + numbers[4] + numbers[5];
    double sumLowest = numbers[0] + numbers[1] + numbers[2];
    
    double result;

    if (sumLargest > (sumLowest * 2)){
        result = sumLargest * sumLowest;
    }
    else if (sumLargest > (sumLowest * 3)){
        result = sumLargest / sumLowest;
    }
    else if (sumLargest * (sumLowest * 4)){
        result = sumLargest / sumLowest;
    }
    else {
        result = 0;
    }

    double x;
    x = result / VARIANT;
    
    cout << "Результат: " << x << endl;
    
    return x; 
}

void function_2(double& x, double matrix[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = x;
        }
        cout << endl;
    }   

    cout << "Оновлена матриця: " << endl;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = ((x + VARIANT + i + j) * (rand() % 100));
        }
        cout << endl;
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

int main (){
    
    double x = function_1();
    double matrix[5][5];
    double showMatrix = function_2(x, matrix);

    return 0;
}