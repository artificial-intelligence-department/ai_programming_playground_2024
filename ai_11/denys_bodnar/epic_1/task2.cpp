#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

int rDice() {
    return rand() % 6 + 1;
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    srand(time(0));

    cout << "Roll Dice (with pc)\n";

    int p_dice1 = rDice();
    int p_dice2 = rDice();
    int p_total = p_dice1 + p_dice2;

    cout << "Ви кинули: " << p_dice1 << " i " << p_dice2 << endl;
    cout << "Ваша сума: " << p_total << endl;

    int c_dice1 = rDice();
    int c_dice2 = rDice();
    int c_total = c_dice1 + c_dice2;

    cout << "Комп'ютер кинув: " << c_dice1 << " i " << c_dice2 << endl;
    cout << "Сума комп'ютера: " << c_total << endl;

    if (p_total > c_total) {
        cout << "Ви виграли!" << endl;
    } else if (c_total > p_total) {
        cout << "Комп'ютер виграв!" << endl;
    } else {
        cout << "Нічия!" << endl;
    }

    return 0;
}
