#include <iostream>
#include <vector>
#include <algorithm> // sort і rotate
#include <iterator> // unique

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> a(N);
    for(int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // забираємо дублікати
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), it));

    // розмір array
    cout << a.size() << endl;

    sort(a.begin(), a.end());

    // повертаємо на К позицій
    K = K % a.size(); // нормалізуєм 
    rotate(a.begin(), a.begin() + K, a.end());

    for(const int &num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
