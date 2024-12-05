#include <iostream>
#include <fstream>
#include <string>
#include <cmath> // для математичних функцій
using namespace std;

const int VARIANT = 43; //константа для номеру варіанта

//ex1
double function_1(){
    double a, b, f;
    int c, d, e;
    cout << "Введіть два дійсних числа a, b: ";
    cin >> a, b;
    cout << "Введіть три цілі числа c, d, e: ";
    cin >> c, d, e;
    cout << "одне дійсне число з подвійною точністю f: ";
    cin >> f;

    double values[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5 - i; ++j){
            if (values[j] > values[i]){
                double temp = values[j];
                values[j] = values[j + 1];
                values[j+1] = temp;
            }
        }
    }
    
    double largest_sum = values [5] + values [4] + values[3];
    double smallest_sum = values [0] + values [1] + values[2];

    double result = 0;
    if (largest_sum > smallest_sum * 4){
        result = largest_sum + smallest_sum;
    } else if (largest_sum > smallest_sum * 3){
        result = largest_sum / smallest_sum;
    } else if (largest_sum > smallest_sum * 2){
        result = largest_sum * smallest_sum;
    }

    result /= VARIANT;
    cout << "Результат: " << result << endl;
    return result;
}
