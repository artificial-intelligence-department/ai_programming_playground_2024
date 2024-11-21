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

    int a, b, c;
    
    cin >> a >> b >> c;

    // Видалення заданих чисел
    r.erase(remove(r.begin(), r.end(), a), r.end());
    r.erase(remove(r.begin(), r.end(), b), r.end());
    r.erase(remove(r.begin(), r.end(), c), r.end());

    // Побудова нового масиву сум
    vector<int> sums;
    for (size_t i = 1; i < r.size(); ++i) {
        sums.push_back(r[i - 1] + r[i]);
    }

    // Вивід результату
    cout << sums.size() << endl;
    for (int sum : sums) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
