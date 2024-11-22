#include <iostream>
#include <string>

using namespace std;

int main() {

    int n, m, count = 0; // Використано цілочисельні змінні
    cin >> n >> m;
    
    string* all_drinks = new string[n + m]; // Використано вказівник для динамічного масиву
    string drink;

    int i = 0;
    while (i < n) { // Цикл while для введення першої групи напоїв
        cin >> drink;
        all_drinks[count++] = drink;
        i++;
    }
    
    int j = 0;
    while (j < m) {     // Цикл while для введення другої групи напоїв
        cin >> drink;
        all_drinks[count++] = drink;
        j++;
    }
    
    // Використано цілочисельні змінні для підрахунку унікальних елементів
    int unique_count = 0; 
    bool is_unique;
    
    
    int k = 0;
    while (k < count) { // Цикл while для перевірки унікальності напоїв
        is_unique = true;

        int l = 0;
        while (l < k) {
           
            if (all_drinks[k] == all_drinks[l]) { // Використано умовний оператор if для порівняння елементів
                is_unique = false;
                break; // Оператор break для виходу з циклу
            }
            l++;
        }

        if (is_unique) {
            unique_count++;
        }
        k++;
    }

    cout << unique_count << endl;    // Оператор виведення даних

    delete[] all_drinks; // Звільнення пам'яті

    return 0;
}
