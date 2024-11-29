#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

void flip(uint64_t &a, int R, int C) {
    //Calculate position, create a mask, reverse the bit
    a ^= (1ULL << (R * 8 + C));
}

int main() {
    //Variables for board and number of spells
    uint64_t a;
    int N;
    cin >> a;
    cin >> N;

    //Create vector for the position of the spell
    vector<pair<int, int>> spells(N);
    for (int i = 0; i < N; ++i) {
        cin >> spells[i].first >> spells[i].second;
        spells[i].first--;
        spells[i].second--;
    }

    //
    for (int i = 0; i < N; ++i) {
        int R = spells[i].first;
        int C = spells[i].second;
        //Changes all Rows
        for (int j = 0; j < 8; ++j) {
            flip(a, R, j);
        }
        //Changes all Cols
        for (int k = 0; k < 8; ++k) {
            flip(a, k, C);
        }
        //Gets rid of intersections
        flip(a, R, C);
    }

    //Prints final situation on the board
    cout << a << endl;
    return 0;
}
