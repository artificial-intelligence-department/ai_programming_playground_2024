#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Загальна кількість клітинок
    int total_cells = n * m;

    // Визначаємо переможця
    if (total_cells % 2 == 0) {
        cout << "Dragon" << endl;
    } else {
        cout << "Imp" << endl;
    }

    return 0;
}
