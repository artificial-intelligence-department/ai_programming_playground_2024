#include <iostream>
#include <vector>
#include <string>

using namespace std;

using CharVector = vector<char>;
using Matrix = vector<CharVector>;

int main() {
    int height, width;
    cin >> height >> width;

    Matrix cave(width, CharVector(height));

    for (int row = 0; row < height; row++) {
        string line;
        cin >> line;
        for (int col = 0; col < width; col++) {
            cave[col][row] = line[col];
        }
    }
    cout << '\n';

    for (int col = 0; col < width; col++) {
        for (int row = height - 1; row >= 0; row--) {
            if (cave[col][row] == 'S') {
                int dropPos = height - 1;

                for (int checkRow = row + 1; checkRow < height; checkRow++) {
                    if (cave[col][checkRow] == 'X' || cave[col][checkRow] == 'S') {
                        dropPos = checkRow - 1;
                        break;
                    }
                }

                if (dropPos != row) {
                    cave[col][row] = 'O';
                    cave[col][dropPos] = 'S';
                }
            }
        }
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            cout << cave[col][row];
        }
        cout << '\n';
    }

    return 0;
}