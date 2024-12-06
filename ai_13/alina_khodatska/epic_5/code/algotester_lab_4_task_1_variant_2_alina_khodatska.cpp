#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);  // використовуємо вектор, бо масив не може змінювати розмір під час виконання

    for (int i = 0; i < N; ++i) {  // цикл для введення елементів масиву
        cin >> a[i];
    }

    // Видалення дублікатів
    sort(a.begin(), a.end()); 
	auto last = unique(a.begin(), a.end()); // Повертає ітератор на перший дублікат
	a.erase(last, a.end()); // Видаляємо дублікати

    // Обертання масиву на K
    int M = a.size(); // Розмір масиву після видалення дублікатів
    K = K % M; // У випадку, якщо K більше ніж розмір масиву
    rotate(a.begin(), a.begin() + K, a.end()); 

    // Виведення результату
    cout << M << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
