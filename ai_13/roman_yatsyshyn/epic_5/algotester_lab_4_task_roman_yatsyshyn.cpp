#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int element = 0;    
    int n = 0;
    cin >> n;

    vector<int> arr;
    vector<int> mod0, mod1, mod2;

    for (int c = 0; c < n; c++) {
        cin >> element;
        arr.push_back(element);
    }

    for (int num : arr) {
        if (num % 3 == 0) mod0.push_back(num);
        else if (num % 3 == 1) mod1.push_back(num);
        else mod2.push_back(num);
    }

    // Сортування
    sort(mod0.begin(), mod0.end());
    sort(mod1.begin(), mod1.end(), greater<int>());
    sort(mod2.begin(), mod2.end());

    // Об'єднання частин
    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    vector<int>::iterator it;
    it = unique(result.begin(), result.end());

    int M = distance(result.begin(), it);
    result.resize(distance(result.begin(), it));

    cout << M << endl;
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}