#include <iostream>
using namespace std;

int main() {
    double tomatoPrice = 9.6, cucumberPrice = 6.9, dillPrice = 2.0001; 
    int tomatoNum, cucumberNum, dillNum; 
    
    cout << "Введіть кількість помідорів: ";
    cin >> tomatoNum;

    cout << "Введіть кількість огірків: ";
    cin >> cucumberNum;

    cout << "Введіть кількість пучків кропу: ";
    cin >> dillNum;

    cout << tomatoPrice * tomatoNum + cucumberPrice * cucumberNum + dillPrice * dillNum;

    return 0;
}

