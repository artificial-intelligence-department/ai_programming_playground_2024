#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    
    // Зчитування першого масиву
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Зчитування другого масиву
    cin >> M;
    vector<int> b(M);
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }

    // Визначення кількості спільних елементів
    int spilne = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a[i] == b[j]) {
                ++spilne;
                break;
            }
        }
    }

    // Визначення кількості унікальних елементів
    vector<int> combined = a;
    for (int i = 0; i < M; ++i) {
        combined.push_back(b[i]);
    }

    // Видалення дублікатів
    sort(combined.begin(), combined.end());
    combined.erase(unique(combined.begin(), combined.end()), combined.end());

    int uniqueElements = combined.size();

    // Вивід результатів
    cout << spilne << endl;
    cout << uniqueElements << endl;

    return 0;
}
