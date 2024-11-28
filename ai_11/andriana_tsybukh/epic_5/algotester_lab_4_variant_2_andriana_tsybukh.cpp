#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

// видалення дублікатів
void removeDuplicates(vector<int>& a) {
    sort(a.begin(), a.end());
    int uniqueIndex = 0;

    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[uniqueIndex]) {
            ++uniqueIndex;
            a[uniqueIndex] = a[i];
        }
    }

    a.resize(uniqueIndex + 1); // обрізаєм до розміру унікальних елементів
}

// ротація масиву
void rotateArray(vector<int>& a, int K) {
    int N = a.size();
    vector<int> temp(N);
    for (int i = 0; i < N; ++i) {
        temp[(i + N - K) % N] = a[i];
    }
    a = temp;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    removeDuplicates(a);
    cout << a.size() << endl;

    // повертаємо на К позицій
    K = K % a.size(); // нормалізуєм K
    rotateArray(a, K);

    for (const int &num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}