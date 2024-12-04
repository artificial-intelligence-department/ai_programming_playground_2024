#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main2() {
    int N, K;
    cin >> N >> K;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }

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

    K %= a.size();
    rotate(a.begin(), a.begin() + K, a.end());

    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    return 0;
}




#include <iostream>

using namespace std;

// Сортування бульбашкою
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int removeDuplicates(int a[], int n) {
    if (n == 0) return 0;
    
    int uniqueCount = 1; 
    
    for (int i = 1; i < n; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (a[i] == a[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            a[uniqueCount] = a[i];
            uniqueCount++;
        }
    }
    return uniqueCount;
}

void rotate(int a[], int n, int k) {
    k = k % n;
    int temp[1000];

    for (int i = 0; i < n; ++i) {
        temp[(i + n - k) % n] = a[i];
    }

    for (int i = 0; i < n; ++i) {
        a[i] = temp[i];
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    int a[1000]; 
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    N = removeDuplicates(a, N);

    bubbleSort(a, N);

    rotate(a, N, K);

    cout << N << endl;
    for (int i = 0; i < N; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
