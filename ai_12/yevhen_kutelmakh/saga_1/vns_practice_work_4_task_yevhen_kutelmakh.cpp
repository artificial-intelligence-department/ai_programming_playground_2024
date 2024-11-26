#include <iostream>
using namespace std;

/*
Варіант 12. Написати програму, яка вводить з клавіатури 5
дробових чисел і обчислює їх середнє арифметичне.
*/

const int count = 5;

struct Drob{
    int chis;
    int znam;
};

double findAvg(Drob *arr) {
    double sum = 0;
    int counter = 0;
    do {
        sum += static_cast<double>(arr[counter].chis) / arr[counter].znam;
        counter++;
    } while(counter < count);
    return sum/5;
}

int main() {
    cout << "Enter 5 fractional numbers(first numerator, then denominator): \n";
    Drob numbers[count];
    for(int i = 0; i < count; i++) {
        cout << "Number #" << i+1 << ": ";
        cin >> numbers[i].chis >> numbers[i].znam;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(23523, '\n');
            cout << "Incorrect input, try agian!\n";
            i--;
        }
        else if(numbers[i].znam==0) {
            cout << "You can`t divide by 0! Enter your number again:\n";
            i--;
        }
    }
    cout << "The arithmetic average of your 5 numbers is: " << findAvg(numbers);
    return 0;
}