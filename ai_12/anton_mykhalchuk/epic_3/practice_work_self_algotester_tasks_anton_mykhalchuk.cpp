#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, winVasyl = 0, winKolia = 0, fullWinVasyl = 0, fullWinKolia = 0;
    string wins;

    cin >> n;
    cin >> wins;
    for (char i : wins) {
        (i == 'V') ? winVasyl += 1 : winKolia += 1;
        if ((winVasyl >= 11) && (winVasyl - winKolia >= 2)) {
            winVasyl = 0;
            winKolia = 0;
            fullWinVasyl += 1;
        }
        else if ((winKolia >= 11) && (winKolia - winVasyl >= 2)) {
            winVasyl = 0;
            winKolia = 0;
            fullWinKolia += 1;
        }
    }
    cout << fullWinKolia<< ':' << fullWinVasyl << endl;
    if ((winVasyl > 0) || (winKolia > 0)) 
        cout << winKolia << ':' << winVasyl;
}

