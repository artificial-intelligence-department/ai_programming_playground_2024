#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 100000) {
        return 1;
    }

    vector<int> r(N);
    for (int i = 0; i < N; ++i) {
        cin >> r[i];
        if (r[i] < 0 || r[i] > 100000) {
            return 1;
        }
    }

    int toRemove[3];
    for (int i = 0; i < 3; ++i) {
        cin >> toRemove[i];
        if (toRemove[i] < 0 || toRemove[i] > 100000) {
            return 1;
        }
    }

    vector<int> filteredArray;
    for (int num : r) {
        if (num != toRemove[0] && num != toRemove[1] && num != toRemove[2]) {
            filteredArray.push_back(num);
        }
    }

    if (filteredArray.size() > 1) {
        vector<int> sumArray(filteredArray.size() - 1);
        for (size_t i = 0; i < filteredArray.size() - 1; ++i) {
            sumArray[i] = filteredArray[i] + filteredArray[i + 1];
        }

        cout << sumArray.size() << endl;
        for (int sum : sumArray) {
            cout << sum << " ";
        }
    } else {
        cout << 0 << endl;
    }

    return 0;
}
