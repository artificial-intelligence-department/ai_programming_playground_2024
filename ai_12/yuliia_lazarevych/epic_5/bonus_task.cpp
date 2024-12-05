//lab 3 without stl
#include <iostream>
#include <vector>
using namespace std;

void sortAscending(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void sortDescending(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            if (arr[i] < arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    //видаляємо дублікати вручну
    vector<int> uniqueArr;
    for (int i = 0; i < N; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueArr.size(); ++j) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueArr.push_back(arr[i]);
        }
    }

    //поділяємо на групи
    vector<int> group0, group1, group2;
    for (int x : uniqueArr) {
        if (x % 3 == 0) group0.push_back(x);
        else if (x % 3 == 1) group1.push_back(x);
        else group2.push_back(x);
    }

    //сортуємо групм вручну
    sortAscending(group0);
    sortDescending(group1);
    sortAscending(group2);

    //об'єднануємо групи
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
