#include <iostream>

using namespace std;

int main() {

int present;
int cash[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
int banknotes = 0;

cout << "Введіть ціну подарунка: ";
cin >> present;

for (int i = 0; i < 9; ++i) {
    banknotes += present / cash[i];
    present %= cash[i];
}

cout << "Кількість необхідних купюр: " << banknotes;

return 0;
}
