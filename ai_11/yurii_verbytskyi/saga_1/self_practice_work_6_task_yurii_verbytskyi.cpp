#include <iostream>
#include <vector>

using namespace std;

struct Filled {
    int row;
    int col;
};

/* Matrix for check
0 1 0 0 1 0 0 0
0 0 0 0 0 0 1 0
1 1 0 0 1 0 0 1
0 0 0 0 0 0 0 0
1 0 0 1 0 0 1 1
0 0 0 0 0 0 0 0
0 1 1 0 1 0 0 0
0 0 0 1 0 1 0 0
*/ 
int main() {
    const int size = 8;
    int board[size][size];

    int r = 0, c = 0;
    cout << "Enter board (0 or 1): \n";
    do {
        cin >> board[r][c];

        if (board[r][c] != 0 && board[r][c] != 1) {
            cout << "Wrong value! Enter 0 or 1.\n";
            continue; 
        }
        c++;
        if (c == size) {
            c = 0;
            r++;
        }
    } while (r < size);

    vector<Filled> filledcells;  
    int rowCounts[size] = {0};   

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 1) {
                filledcells.push_back({i + 1, j + 1}); 
                rowCounts[i]++;
            }
        }
    }

   
    cout << "\nQuantity of filled cells in each row:\n";
    for (int i = 0; i < size; i++) {
        cout << "Row " << i + 1 << ": " << rowCounts[i] << endl;
    }

    
    cout << "\nCoordinates of filled cells: \n";
    for (const auto& fill : filledcells) {
        cout << "(" << fill.row << ", " << fill.col << ") ";
    }
    cout << endl;

   
    int sum_of_filled_cells = filledcells.size();
    cout << "Sum of filled cells: " << sum_of_filled_cells << endl;

    return 0;
}
