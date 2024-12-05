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

    //видаляємо дублікати
    sort(arr.begin(), arr.end());  //спершу сортуємо для застосування std::unique
    arr.erase(unique(arr.begin(), arr.end()), arr.end());  //видаляємо дублікати

    //створюю три групи за остачею від ділення на 3
    vector<int> group0, group1, group2;
    for (int x : arr) {
        if (x % 3 == 0) group0.push_back(x);
        else if (x % 3 == 1) group1.push_back(x);
        else group2.push_back(x);
    }

    //сортую групи
    sort(group0.begin(), group0.end());  //за зростанням
    sort(group1.rbegin(), group1.rend());  //за спаданням
    sort(group2.begin(), group2.end());  //за зростанням

    //об'єдную всі групи
    vector<int> result;
    result.insert(result.end(), group0.begin(), group0.end());
    result.insert(result.end(), group1.begin(), group1.end());
    result.insert(result.end(), group2.begin(), group2.end());

    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
