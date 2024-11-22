#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int a[1000];
    bool exists[101] = {false}; 

    int size = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (!exists[x]) {
            a[size++] = x;
            exists[x] = true; 
        }
    }

    sort(a, a + size);


    K %= size;  
    int rotated[1000]; 

    for (int i = 0; i < size; i++) {
        rotated[i] = a[(i + K) % size];
    }

    cout << size << endl;
    for (int i = 0; i < size; i++) {
        cout << rotated[i] << " ";
    }
    cout << endl;

    return 0;
}
