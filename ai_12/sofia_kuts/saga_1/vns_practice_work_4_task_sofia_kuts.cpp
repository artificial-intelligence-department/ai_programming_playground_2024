#include <iostream>
#include <vector>
#include <limits> // Для використання мінімальних і максимальних значень

using namespace std;

int main() {
    int n; 
    cout << "Введіть кількість чисел у послідовності: ";
    cin >> n;

    if (n <= 0) {
        cout << "Кількість чисел повинна бути більшою за 0.\n";
        return 1; 
    }

    vector<double> numbers(n); 
    double sum = 0.0; 
    double min_val = numeric_limits<double>::max(); 
    double max_val = numeric_limits<double>::lowest(); 
    cout << "Введіть " << n << " дробових чисел:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Число " << i + 1 << ": ";
        cin >> numbers[i];
        sum += numbers[i];
        
        if (numbers[i] < min_val) {
            min_val = numbers[i];
        }
        if (numbers[i] > max_val) {
            max_val = numbers[i];
        }
    }

    double average = sum / n; 

    cout << "\nСереднє арифметичне: " << average << endl;
    cout << "Мінімальне число: " << min_val << endl;
    cout << "Максимальне число: " << max_val << endl;

    return 0; 
}

