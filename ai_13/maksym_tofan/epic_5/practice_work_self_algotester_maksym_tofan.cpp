#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }


    set<int> unique_elements(a.begin(), a.end());


    vector<int> sorted_a(unique_elements.begin(), unique_elements.end());


    N = sorted_a.size();


    K = K % N;  


    cout << N << endl;


    for (int i = 0; i < N; ++i) {
        cout << sorted_a[(i + K) % N] << " ";
    }
    cout << endl;

    return 0;
}