#include <iostream>
#include <string>

using namespace std;

// Використано рекурсивну функцію
void count_days(int start_index, int remainder, int days_count[], int base_count) { //Використовує параметри start_index, remainder, days_count[] і base_count
    if (remainder == 0) { 
        return;
    }
    days_count[(start_index) % 7]++; // Математична операція (залишок від ділення)
    count_days(start_index + 1, remainder - 1, days_count, base_count); // Рекурсивний виклик
}

int main() {
    string week_days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; // Одновимірний масив для днів тижня
    
    string start_day;
    int n;
    
    cin >> start_day >> n; // Оператор введення даних

    int start_index = 0;
    for (int i = 0; i < 7; i++) {  // Цикл for для пошуку індекса початкового дня
        if (week_days[i] == start_day) {  // Умовний оператор (if) для перевірки умови
            start_index = i;
            break;  // Оператор break для примусового завершення циклу
        }
    }
    
    int base_count = n / 7;  // Математична операція (цілочисельне ділення)
    int remainder = n % 7;   // Математична операція (залишок від ділення)
    
    int days_count[7] = {base_count, base_count, base_count, base_count, base_count, base_count, base_count}; // Одновимірний масив для кількості днів

    count_days(start_index, remainder, days_count, base_count); // Виклик рекурсивної функції
    
    for (int i = 0; i < 7; ++i) {  // Цикл for для виведення масиву
        cout << days_count[i] << " ";  // Оператор виведення
    }
    cout << endl; 
    
    return 0;
}
