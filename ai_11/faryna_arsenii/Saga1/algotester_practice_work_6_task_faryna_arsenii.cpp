#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    int max_length = 0;
    int current_length = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            current_length++;
        } 
        else {
            if (max_length < current_length){
                max_length = current_length;
            }
            current_length = 0;
        }
    }
    if (max_length < current_length){
        max_length = current_length;
    }

    cout << max_length << endl;

    return 0;
}
