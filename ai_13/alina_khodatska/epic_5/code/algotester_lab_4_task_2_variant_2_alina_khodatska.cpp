#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для видалення дублікатів
void removeDuplicates(vector<int>& a) {
    sort(a.begin(), a.end());
    int uniqueCount = 0;
	for (int i = 1; i < a.size(); ++i) { // Перевірка на дублікати
        if (a[i] != a[uniqueCount]) {
            ++uniqueCount;
            a[uniqueCount] = a[i];
        }
    }
    a.resize(uniqueCount + 1);
}

// Функція для обертання масиву
void rotateArray(vector<int>& a, int K) {
    int n = a.size();
    K = K % n;
    vector<int> temp(K);
	for (int i = 0; i < K; ++i) { // Зберігаємо перші K елементів
        temp[i] = a[i];
    }
	for (int i = K; i < n; ++i) { // Переміщаємо елементи на K позицій вліво
        a[i - K] = a[i];
    }
	for (int i = 0; i < K; ++i) { // Переміщаємо збережені елементи на кінець
        a[n - K + i] = temp[i];
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);

	for (int i = 0; i < N; ++i) { // цикл для введення елементів масиву
        cin >> a[i];
    }

    // Видалення дублікатів
    removeDuplicates(a);

    // Обертання масиву на K
    rotateArray(a, K);

    // Виведення результату
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
