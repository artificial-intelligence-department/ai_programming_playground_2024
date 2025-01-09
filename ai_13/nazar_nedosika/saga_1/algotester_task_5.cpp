#include <iostream>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n;

    int batmanW = 0; 
    int supermanW = 0;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        int game_state = a ^ b ^ c;

        if (game_state != 0) supermanW++;
        else batmanW++;
    }
    cout << supermanW << "-" << batmanW;

    return 0;
}