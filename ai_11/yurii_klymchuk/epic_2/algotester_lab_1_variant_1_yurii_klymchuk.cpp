#include <iostream>
using namespace std;

int main(){
    long long H,M;
    long long h [3], m[3];

    cin >> H >> M;

    for (int i = 0; i < 3; i++){
        cin >> h[i] >> m[i];
        H -= h[i];
        M -= m[i];
    }

    for (int i = 0; i < 3; i++){
        if (h[i] != 0 && m[i] != 0){
            cout << "NO";
            return 0;
        }
    }

    if (H > 0 && M > 0){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}