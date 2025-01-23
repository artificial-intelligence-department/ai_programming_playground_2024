#include <iostream>
#include <vector> 
using namespace std;

int main() {
    int n;
    cin >> n;
    const int N = n;
    vector<vector<char>> v;
    //char arr[N][N];
    char white[] = "s";
    char black[] = "S";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (v[i][j] == "s" && v[i][k] == black) {
                    cout << "C243 " << i << " " << j << " " << i << " " << k;
                    return 0;
                }
            }
        }
    }
    cout << "C243 none";
    return 0;
}