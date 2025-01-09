#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) 
        return 1;
    else
        return n * factorial(n - 1); 
}

int main(){
    int n;
    cout << "Введіть число: ";
    cin >> n;
    cout << "Факторіал числа " << n << ": " << factorial(n);

    return 0;

}


