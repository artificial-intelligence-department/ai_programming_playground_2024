#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

const double imperial_mile = 1609.344;
const double mile = 1609.347;
const int bonus = 200000;
const int discount = 100000;


bool isPalindrome(int distance) {
    int reversed = 0, original = distance;
    
    // Якщо число від'ємне, то це не може бути паліндромом
    if (distance < 0) {
        return false;
    }

    // Зворотне число для порівняння
    while (distance > 0) {
        int digit = distance % 10;   // остання цифра
        reversed = reversed * 10 + digit;
        distance /= 10;  // відкидаємо останню цифру
    }

    // Якщо число і його зворотне значення співпадають, то це паліндром
    return original == reversed;
}

int CalculateBonus(int distance, int total_bonus){



    return 0;
}




int main(){

    string user_name;
    int total_bonus;
    int distance;

    cout << "Введіть ваше ім'я: ";
    cin >> user_name;

    cout << "Введіть відстань доставки у метрах: ";
    cin >> distance;

    if(isPalindrome(distance)){
        total_bonus += bonus;
        cout << "Ваша відстань паліндром + 200 км бонусів: " << endl;
    }

    cout << "Ваші поточні бонуси: " << total_bonus/1000 << "км" << endl;
    cout << "Доступна знижка: " << total_bonus/100000 << endl;



    
    
    return 0;
}