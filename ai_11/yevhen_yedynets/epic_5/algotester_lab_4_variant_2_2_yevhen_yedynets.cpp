#include <iostream>
#include <vector>

using namespace std;

void sortArray(vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = i + 1; j < a.size(); ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

vector<int> removeDuplicates(const vector<int>& a) {
    vector<int> result;
    for (int x : a) {
        if (find(result.begin(), result.end(), x) == result.end()) {
            result.push_back(x);
        }
    }
    return result;
}

void rotateArray(vector<int>& a, int K) {
    int n = a.size();
    K %= n;
    vector<int> temp(a.begin() + K, a.end());
    temp.insert(temp.end(), a.begin(), a.begin() + K);
    a = temp;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);

    for (int i = 0; i < N; ++i)
        cin >> a[i];

    a = removeDuplicates(a);
    sortArray(a);
    rotateArray(a, K);

    cout << a.size() << endl;
    for (int x : a)
        cout << x << " ";
    cout << endl;
    
    return 0;
}
