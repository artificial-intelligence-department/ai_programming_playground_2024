#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> uniqueArr;
    for (int i = 0; i < N; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < uniqueArr.size(); j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            uniqueArr.push_back(arr[i]);
        }
    }

    for (int i = 0; i < uniqueArr.size() - 1; i++) {
        for (int j = 0; j < uniqueArr.size() - i - 1; j++) {
            if (uniqueArr[j] > uniqueArr[j + 1]) {
                int temp = uniqueArr[j];
                uniqueArr[j] = uniqueArr[j + 1];
                uniqueArr[j + 1] = temp;
            }
        }
    }

    N = uniqueArr.size();
    K = K % N;
    vector<int> rotatedArr;
    for (int i = K; i < N; i++) {
        rotatedArr.push_back(uniqueArr[i]);
    }
    for (int i = 0; i < K; i++) {
        rotatedArr.push_back(uniqueArr[i]);
    }

    cout << N << endl;
    for (int i = 0; i < N; i++) {
        if (i != N - 1) {
            cout << rotatedArr[i] << " ";
        } else {
            cout << rotatedArr[i];
        }
    }

    return 0;
}
