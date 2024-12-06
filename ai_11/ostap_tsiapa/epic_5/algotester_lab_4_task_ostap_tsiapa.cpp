#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // Розділяємо масив на три частини
    vector<int> mod0, mod1, mod2;
    for (int num : arr) {
        if (num % 3 == 0) mod0.push_back(num);
        else if (num % 3 == 1) mod1.push_back(num);
        else mod2.push_back(num);
    }

    // Сортуємо кожну частину відповідно до умов
    sort(mod0.begin(), mod0.end());           // Сортуємо по зростанню
    sort(mod2.begin(), mod2.end());           // Сортуємо по зростанню
    sort(mod1.begin(), mod1.end(), greater<int>()); // Сортуємо по спаданням

    // Об'єднуємо всі частини разом в правильному порядку
    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    // Видаляємо дублікати
    auto it = unique(result.begin(), result.end());
    result.resize(distance(result.begin(), it));

    // Виводимо результуючий масив
    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
