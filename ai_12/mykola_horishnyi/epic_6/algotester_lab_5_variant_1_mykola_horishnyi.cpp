#include <iostream>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdint>
using namespace std;

void makeBoard(bitset<64> binBoard, int board[8][8])
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = binBoard[count];
            count++;
        }
    }
}

int main()
{
    uint64_t a;
    cin >> a;
    bitset<64> binBoard(a);
    int board[8][8] = {};
    makeBoard(binBoard, board);
    int questions;
    cin >> questions;
    int coord[questions][2] = {};
    for (int i = 0; i < questions; i++)
    {
        cin >> coord[i][0] >> coord[i][1];
        coord[i][0]--;
        coord[i][1]--;
    }
    int row, column;
    for (int i = 0; i < questions; i++)
    {
        row = coord[i][0];
        column = coord[i][1];
        board[row][column] = (board[row][column] == 1) ? 0 : 1;
        for (int j = 0; j < 8; j++)
        {
            board[row][j] = (board[row][j] == 1) ? 0 : 1;
            board[j][column] = (board[j][column] == 1) ? 0 : 1;
        }
    };

    uint64_t result = 0;

    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 1)
            {
                uint64_t c = pow(2, count);
                result += c;
            }
            count++;
        }
    }
    cout << result;

    return 0;
}

