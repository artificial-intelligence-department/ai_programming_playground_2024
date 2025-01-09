#include <iostream>
using namespace std;

int main() {
    const int price = 4;    // 4. цілочисельна константа для єдиної ціни(для яблук)
    int grams = 0;      // 1. ціле число, для кіькості грам
    while(grams <= 1000) {  //  8. цикл while для перевірки змінної на кожному етапі
        grams += 100;
        if(grams > 1000) {
            break;      // 11. екстрене завершення після додаткової перевірки 
        } else {
            cout << "For " << grams << " price is: " << (grams / 100) * price << endl;
            continue;
        }
    } 

    return 0;
}