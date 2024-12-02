#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Видаляємо дублікати
    set<int> unique_elements(a.begin(), a.end());
    vector<int> unique_array(unique_elements.begin(), unique_elements.end());

    // Сортуємо масив
    sort(unique_array.begin(), unique_array.end());

    // Обрізаємо значення K, якщо воно більше за розмір унікального масиву
    K %= unique_array.size();

    // Обертаємо масив на K
    rotate(unique_array.begin(), unique_array.begin() + K, unique_array.end());

  
    cout << unique_array.size() << endl;
    for (int num : unique_array) {
        cout << num << " ";
    }
    cout << endl;




    return 0;
}








