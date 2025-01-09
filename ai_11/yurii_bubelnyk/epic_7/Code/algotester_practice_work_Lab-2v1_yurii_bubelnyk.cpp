#include <iostream>
#include <vector> // для списку розмір якого визначає користувач
using namespace std;

int main() {
    int N; 
    cin >> N;

    if (N > 1e5 || N < 1) {
        return 1;
    }

    if (N <= 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> r(N); // список з N елементів

    for (int i = 0; i < N; i++) {
        cin >> r[i];
        if (r[i] > 1e5 || r[i] < 0) {
            return 1;
        }
    }
    // запис початкових значень min та max
    int max = r[0], min = r[0];
    int maxIndex = 0, minIndex = 0;

    for (int i = 1; i < N; i++) {
        if (r[i] > max) {
            max = r[i];
            maxIndex = i;
        }
        if (r[i] < min) {
            min = r[i];
            minIndex = i;
        }
    }
    // нові значення max та min
    int newMax = (maxIndex == 0) ? r[1] : r[0];
    int newMin = (minIndex == 0) ? r[1] : r[0];
    // цикл для знаходження новий значень max та min
    for (int i = 0; i < N; i++) {
        if (i != maxIndex) {
            if (r[i] > newMax) {
                newMax = r[i];
            }
        }
        if (i != minIndex) {
            if (r[i] < newMin) {
                newMin = r[i];
            }
        }
    }
    // різниця між парами елемментів
    int rMax = newMax - min; 
    int rMin = max - newMin; 

    if (rMax < rMin) {
        cout << rMax << endl;
    } else {
        cout << rMin << endl;
    }

    return 0;
}

