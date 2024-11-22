#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    set<int> unique_elements(a.begin(), a.end());
    a.assign(unique_elements.begin(), unique_elements.end());

    if (a.empty()) {
        cout << 0 << endl;
        return 0;
    }

    sort(a.begin(), a.end());

    if (K > 0) {
        rotate(a.begin(), a.begin() + K, a.end());
    }

    // Вивід результату
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

// Видалення повторюваних елементів без STL
vector<int> removeDuplicates(const vector<int>& a) {
    vector<int> result;
    for (int num : a) {
        bool found = false;
        for (int res_num : result) {
            if (res_num == num) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(num);
        }
    }
    return result;
}

// Сортування бульбашкою
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Обрізання на K
void rotateArray(vector<int>& a, int K) {
    int n = a.size();
    K %= n;
    vector<int> temp;
    for (int i = 0; i < K; ++i) {
        temp.push_back(a[i]);
    }
    for (int i = 0; i < n - K; ++i) {
        a[i] = a[i + K];
    }
    for (int i = 0; i < temp.size(); ++i) {
        a[n - K + i] = temp[i];
    }
}

int main_2() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Видалення повторів
    a = removeDuplicates(a);

    // Сортування
    bubbleSort(a);

    // Обрізання на K
    rotateArray(a, K);

    // Вивід результату
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    return 0;
}
