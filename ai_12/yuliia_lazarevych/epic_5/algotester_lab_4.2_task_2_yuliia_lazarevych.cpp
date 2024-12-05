#include <iostream>
#include <vector>

using namespace std;

//використовуємо функцію для видалення дублікатів
void removeDuplicates(vector<int>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = i + 1; j < a.size();) {
            if (a[i] == a[j]) {
                a.erase(a.begin() + j); // Видалення дубліката
            } else {
                j++;
            }
        }
    }
}

//використовуємо функцію для сортування масиву вибором
void sortArray(vector<int>& a) {
    for (size_t i = 0; i < a.size() - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < a.size(); j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

//використовуємо функцію для зсуву масиву на K елементів
void rotateArray(vector<int>& a, int K) {
    K %= a.size(); //уникаємо зайвих обертань
    vector<int> temp(a.begin(), a.begin() + K);
    for (size_t i = 0; i < a.size() - K; i++) {
        a[i] = a[i + K];
    }
    for (size_t i = 0; i < temp.size(); i++) {
        a[a.size() - K + i] = temp[i];
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    //видаляємо дублікати
    removeDuplicates(a);

    sortArray(a);

    //зсуваємо на K
    rotateArray(a, K);

    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
