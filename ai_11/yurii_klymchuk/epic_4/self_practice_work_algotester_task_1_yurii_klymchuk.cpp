#include <iostream>
#include <vector>
using namespace std;

int main() {
    //змінні для вводу користувача
    int n;
    cin >> n;

    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    int a, b, c;
    cin >> a >> b >> c;

    //записуємо не співпадаючі елементи у новий масив
    vector<int> r_new;
    for (int i = 0; i < n; i++) {
        if (r[i] != a && r[i] != b && r[i] != c) {
            r_new.push_back(r[i]);
        }
    }

    //знаходимо розмір нового масиву і перевіряємо його
    int M = r_new.size() - 1;
    if (M <= 0) {
        cout << 0;
        return 0;
    }

    //записуємо суму сусідних елементів у окремий масив
    vector<int> M_sum(M);
    for (int i = 0; i < M; i++) {
        M_sum[i] = r_new[i] + r_new[i + 1];
    }

    //виводимо розмір і сам масив
    cout << M << endl;
    for (int i = 0; i < M; i++) {
        cout << M_sum[i] << " ";
    }
    return 0;
}