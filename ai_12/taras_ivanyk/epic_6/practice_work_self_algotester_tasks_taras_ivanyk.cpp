// algotester lab 5v1
#include <iostream>
#include <cstdint> 
#include <vector>
using namespace std;

void BallCondition(uint64_t &table, int row, int col) {
    int position = row * 8 + col; 
    table = table ^ (1ULL << position);  // зсув 1 біта на потрібну нам position
}
int main() {
    uint64_t table; 
    int N;        

    cin >> table;
    cin >> N;

    vector<pair<int, int>> mantras(N);
    for (int i = 0; i < N; ++i) {
        cin >> mantras[i].first >> mantras[i].second;
        mantras[i].first--;  
        mantras[i].second--;
    }
    for (const auto &mantra : mantras) {
        int row = mantra.first;
        int col = mantra.second;

        for (int c = 0; c < 8; ++c) {
            BallCondition(table, row, c);
        }
        for (int r = 0; r < 8; ++r) {
            if (r != row) { 
                BallCondition(table, r, col);
            }
        }
    }
    cout << table << endl;
    return 0;
}