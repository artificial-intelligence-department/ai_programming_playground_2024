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

    // Розділяємо на три групи за остачею від ділення на 3
    vector<int> group0, group1, group2;
    
    for (int num : arr) {
        if (num % 3 == 0) group0.push_back(num);
        else if (num % 3 == 1) group1.push_back(num);
        else group2.push_back(num);
    }

    // Сортуємо за умовами: group0 та group2 по зростанню, group1 по спаданню
    sort(group0.begin(), group0.end());
    sort(group1.begin(), group1.end(), greater<int>());
    sort(group2.begin(), group2.end());

    // Об'єднуємо всі три групи
    vector<int> result;
    result.insert(result.end(), group0.begin(), group0.end());
    result.insert(result.end(), group1.begin(), group1.end());
    result.insert(result.end(), group2.begin(), group2.end());

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
