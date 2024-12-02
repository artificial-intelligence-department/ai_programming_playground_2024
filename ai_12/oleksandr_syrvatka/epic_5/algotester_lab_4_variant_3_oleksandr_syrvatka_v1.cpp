#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Розділяємо масив на три частини за остачею від ділення на 3
    vector<int> mod0, mod1, mod2;
    for (int num : arr) {
        if (num % 3 == 0) mod0.push_back(num);
        else if (num % 3 == 1) mod1.push_back(num);
        else mod2.push_back(num);
    }

    // Сортуємо відповідно до умов
    sort(mod0.begin(), mod0.end());  // для остачі 0 - за зростанням
    sort(mod1.rbegin(), mod1.rend());  // для остачі 1 - за спаданням
    sort(mod2.begin(), mod2.end());  // для остачі 2 - за зростанням

    // Об'єднуємо три масиви
    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    // Видаляємо дублікати
    result.erase(unique(result.begin(), result.end()), result.end());

    // Виводимо результат
    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
