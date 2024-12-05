#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    //сортуємо масив
    sort(a.begin(), a.end());

    //видаляємо дублікати
    auto uniqueEnd = unique(a.begin(), a.end());
    a.erase(uniqueEnd, a.end());

    //зсуваємо масив на K
    K %= a.size();
    rotate(a.begin(), a.begin() + K, a.end());
    
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
