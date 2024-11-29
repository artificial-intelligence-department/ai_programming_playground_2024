#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
    }

    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    sort(r.begin(), r.end());

    // Втома без видалення
    int original_tiredness = r[N-1] - r[0];

    // Втома після видалення мінімального елемента
    int tiredness_after_removing_min = r[N-1] - r[1];

    // Втома після видалення максимального елемента
    int tiredness_after_removing_max = r[N-2] - r[0];

    // Мінімальна втома
    int min_tiredness = min(tiredness_after_removing_min, tiredness_after_removing_max);

    cout << min_tiredness << endl;

    return 0;
}