#include <iostream>

using namespace std;

void printMultiplicationTable(int number, int multiplier) {
    if (multiplier > 10) {
        return;
    }
    cout << number << " * " << multiplier << " = " << number * multiplier << endl;
    printMultiplicationTable(number, multiplier + 1);
}

int main() {
    int number; 
    cout << "Таблиця множення на ";
    cin >> number;    
    printMultiplicationTable(number, 1); 
    return 0;
}