#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isWithinBounds(int row, int col)
{
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

void processPawnAttacks(vector<set<char>> &attack, int row, int col, char piece)
{
    if (isWithinBounds(row + 1, col - 1))
        attack[(row + 1) * 8 + (col - 1)].insert(piece);
    if (isWithinBounds(row + 1, col + 1))
        attack[(row + 1) * 8 + (col + 1)].insert(piece);
}

void processRookAttacks(vector<set<char>> &attack, int row, int col, char piece)
{
    for (int i = 0; i < 8; ++i)
    {
        if (i != col)
            attack[row * 8 + i].insert(piece);
        if (i != row)
            attack[i * 8 + col].insert(piece);
    }
}

void processBishopAttacks(vector<set<char>> &attack, int row, int col, char piece)
{
    for (int offset = 1; offset < 8; ++offset)
    {
        if (isWithinBounds(row + offset, col + offset))
            attack[(row + offset) * 8 + (col + offset)].insert(piece);
        if (isWithinBounds(row + offset, col - offset))
            attack[(row + offset) * 8 + (col - offset)].insert(piece);
        if (isWithinBounds(row - offset, col + offset))
            attack[(row - offset) * 8 + (col + offset)].insert(piece);
        if (isWithinBounds(row - offset, col - offset))
            attack[(row - offset) * 8 + (col - offset)].insert(piece);
    }
}

void processKnightAttacks(vector<set<char>> &attack, int row, int col, char piece)
{
    const int moves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
    for (const auto &move : moves)
    {
        int newRow = row + move[0], newCol = col + move[1];
        if (isWithinBounds(newRow, newCol))
            attack[newRow * 8 + newCol].insert(piece);
    }
}

void processKingAttacks(vector<set<char>> &attack, int row, int col, char piece)
{
    for (int dr = -1; dr <= 1; ++dr)
    {
        for (int dc = -1; dc <= 1; ++dc)
        {
            if (dr != 0 || dc != 0)
            {
                int newRow = row + dr, newCol = col + dc;
                if (isWithinBounds(newRow, newCol))
                    attack[newRow * 8 + newCol].insert(piece);
            }
        }
    }
}

int main()
{
    vector<string> chessboard(8);
    for (int i = 0; i < 8; ++i)
    {
        cin >> chessboard[i];
    }

    vector<set<char>> attack(64);

    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            char piece = chessboard[row][col];
            if (piece == 'P')
            {
                processPawnAttacks(attack, row, col, 'P');
            }
            else if (piece == 'R')
            {
                processRookAttacks(attack, row, col, 'R');
            }
            else if (piece == 'B')
            {
                processBishopAttacks(attack, row, col, 'B');
            }
            else if (piece == 'N')
            {
                processKnightAttacks(attack, row, col, 'N');
            }
            else if (piece == 'K')
            {
                processKingAttacks(attack, row, col, 'K');
            }
            else if (piece == 'Q')
            {
                processRookAttacks(attack, row, col, 'Q');
                processBishopAttacks(attack, row, col, 'Q');
            }
        }
    }

    int queries;
    cin >> queries;

    while (queries-- > 0)
    {
        int queryRow, queryCol;
        cin >> queryRow >> queryCol;
        --queryRow;
        --queryCol;

        if (chessboard[queryRow][queryCol] != 'O')
        {
            cout << "X\n";
        }
        else
        {
            const auto &attackingPieces = attack[queryRow * 8 + queryCol];
            if (attackingPieces.empty())
            {
                cout << "O\n";
            }
            else
            {
                for (char piece : attackingPieces)
                {
                    cout << piece;
                }
                cout << endl;
            }
        }
    }

    return 0;
}
