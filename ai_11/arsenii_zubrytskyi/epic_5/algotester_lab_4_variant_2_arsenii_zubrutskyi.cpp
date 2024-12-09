#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortGroup0(vector<int>& group) {
    sort(group.begin(), group.end());
}

void sortGroup1(vector<int>& group) {
    sort(group.begin(), group.end(), greater<int>());
}

void sortGroup2(vector<int>& group) {
    sort(group.begin(), group.end());
}

bool contains(const vector<int>& result, int value) {
    return find(result.begin(), result.end(), value) != result.end();
}

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

    // Сортуємо групи
    sortGroup0(group0);
    sortGroup1(group1);
    sortGroup2(group2);

    // Об'єднуємо всі три групи
    vector<int> result;
    result.insert(result.end(), group0.begin(), group0.end());
    result.insert(result.end(), group1.begin(), group1.end());
    result.insert(result.end(), group2.begin(), group2.end());

    // Видаляємо дублікати вручну
    vector<int> finalResult;
    for (int num : result) {
        if (!contains(finalResult, num)) {
            finalResult.push_back(num);
        }
    }

    // Виводимо результат
    cout << finalResult.size() << endl;
    for (int num : finalResult) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
