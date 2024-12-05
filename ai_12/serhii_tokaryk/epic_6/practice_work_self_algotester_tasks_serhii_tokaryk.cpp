#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int maxLength = 0;
    int currentLength = 0;
    
    for (int i = 0; i < N; i++) {
        if (A[i] >= K) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 0;
        }
    }
    
    cout << maxLength << endl;
    return 0;
}
