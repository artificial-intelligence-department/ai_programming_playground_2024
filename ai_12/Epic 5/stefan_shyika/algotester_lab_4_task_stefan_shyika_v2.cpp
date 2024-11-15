#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    int len = a.size();
    K = K % len;
    rotate(a.begin(), a.begin() + K, a.end());

    cout << len << endl;
    for(int i = 0; i < len; i++){
        if(i != len-1){
            cout << a[i] << " ";
        }else{
            cout << a[i];
        }
    }
}
