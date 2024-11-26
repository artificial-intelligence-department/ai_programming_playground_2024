#include <iostream>
using namespace std;

int main(){
    double input, avg, sum = 0;

    cout << "Введіть п'ять дробових чисел: \n";
    for(double i = 1; i < 6; i++){
        cin >> input;
        sum += input;
        avg = sum / i;
        cout << "Середнє арифметичне з введених чисел: " << avg << endl;
    }

    return 0;
}