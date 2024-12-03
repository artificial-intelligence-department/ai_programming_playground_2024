#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparator(int a, int b) {
    int remA = a % 3;
    int remB = b % 3;

    if (remA == remB) {
        if (remA == 0 || remA == 2) {
            return a < b; 
        } else {
            return a > b; 
        }
    }

    return remA < remB;
}

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), comparator);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());  

    cout << arr.size() << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
