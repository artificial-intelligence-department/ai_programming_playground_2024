#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    int n, m;// Використано цілочисельні змінні
    cin >> n >> m;

    int ties[1000];// Використано одновимірний масив для зберігання кількості краваток
    for (int i = 0; i < n; i++) {
        cin >> ties[i];
    }

    // Використано дійсні змінні для зберігання меж пошуку та результату
    double low = 0.0, high = 1e9, mid;
    double result = 0.0;

    while (high - low > 1e-6) {  // Цикл while для бінарного пошуку
        mid = (low + high) / 2.0;

        int count = 0;

        for (int i = 0; i < n; i++) { // Цикл for для підрахунку кількості краваток, які можна отримати
            count += ties[i] / mid;
        }

        if (count >= m) { // Умовний оператор if для визначення меж бінарного пошуку
            result = mid;
            low = mid;
        } else {
            high = mid;
        }
    }

    cout << fixed << setprecision(7) << result << endl; // Оператор виведення з точною кількістю знаків після коми

    return 0;
}
