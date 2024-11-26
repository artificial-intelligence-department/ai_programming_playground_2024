#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isInBoard(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}
set<char> PawnAttack(vector<vector<char>> &board, int x, int y)
{
    set<char> at;
    if (isInBoard(x - 1, y - 1) && board[x - 1][y - 1] == 'P')
    {
        at.insert('P');
    }
    if (isInBoard(x - 1, y + 1) && board[x - 1][y + 1] == 'P')
    {
        at.insert('P');
    }
    return at;
}
set<char> KingAttack(vector<vector<char>> &board, int x, int y)
{
    set<char> at;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i != 0 || j != 0)
            {
                int newX = x + i;
                int newY = y + j;
                if (isInBoard(newX, newY) && board[newX][newY] == 'K')
                {
                    at.insert('K');
                }
            }
        }
    }
    return at;
}
set<char> RookAttack(vector<vector<char>> &board, int x, int y)
{
    set<char> at;
    for (int i = 0; i < 8; i++)
    {
        if (i != x && board[i][y] == 'R')
            at.insert('R');
        if (i != y && board[x][i] == 'R')
            at.insert('R');
    }
    return at;
}
set<char> BishopAttack(vector<vector<char>> &board, int x, int y)
{
    set<char> at;
    for (int i = 1; x - i >= 0 && y - i >= 0; i++)
    {
        if (isInBoard(x - i, y - i) && board[x - i][y - i] == 'B')
        {
            at.insert('B');
            break;
        }
    }
    for (int i = 1; x - i >= 0 && y + i < 8; i++)
    {
        if (isInBoard(x - i, y + i) && board[x - i][y + i] == 'B')
        {
            at.insert('B');
            break;
        }
    }
    for (int i = 1; x + i < 8 && y - i >= 0; i++)
    {
        if (isInBoard(x + i, y - i) && board[x + i][y - i] == 'B')
        {
            at.insert('B');
            break;
        }
    }
    for (int i = 1; x + i < 8 && y + i < 8; i++)
    {
        if (isInBoard(x + i, y + i) && board[x + i][y + i] == 'B')
        {
            at.insert('B');
            break;
        }
    }
    return at;
}
set<char> QueenAttack(vector<vector<char>> &board, int x, int y)
{
    set<char> at;
    for (int i = 0; i < 8; i++)
    {
        if (i != x && board[i][y] == 'Q')
            at.insert('Q');
        if (i != y && board[x][i] == 'Q')
            at.insert('Q');
    }
    for (int i = 1; x - i >= 0 && y - i >= 0; i++)
    {
        if (isInBoard(x - i, y - i) && board[x - i][y - i] == 'Q')
        {
            at.insert('Q');
            break;
        }
    }
    for (int i = 1; x - i >= 0 && y + i < 8; i++)
    {
        if (isInBoard(x - i, y + i) && board[x - i][y + i] == 'Q')
        {
            at.insert('Q');
            break;
        }
    }
    for (int i = 1; x + i < 8 && y - i >= 0; i++)
    {
        if (isInBoard(x + i, y - i) && board[x + i][y - i] == 'Q')
        {
            at.insert('Q');
            break;
        }
    }
    for (int i = 1; x + i < 8 && y + i < 8; i++)
    {
        if (isInBoard(x + i, y + i) && board[x + i][y + i] == 'Q')
        {
            at.insert('Q');
            break;
        }
    }
    return at;
}
set<char> KnightAttack(vector<vector<char>> &board, int x, int y)
{
    set<char> at;
    int knightMoves[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};
    for (int i = 0; i < 8; i++)
    {
        int newX = x + knightMoves[i][0];
        int newY = y + knightMoves[i][1];
        if (isInBoard(newX, newY) && board[newX][newY] == 'N')
        {
            at.insert('N');
        }
    }
    return at;
}
int main()
{
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        set<char> res;
        if (board[x][y] != 'O')
        {
            cout << "X" << endl;
            continue;
        }
        auto pawn = PawnAttack(board, x, y);
        res.insert(pawn.begin(), pawn.end());
        auto king = KingAttack(board, x, y);
        res.insert(king.begin(), king.end());
        auto rook = RookAttack(board, x, y);
        res.insert(rook.begin(), rook.end());
        auto bishop = BishopAttack(board, x, y);
        res.insert(bishop.begin(), bishop.end());
        auto knight = KnightAttack(board, x, y);
        res.insert(knight.begin(), knight.end());
        auto queen = QueenAttack(board, x, y);
        res.insert(queen.begin(), queen.end());
        if (res.empty())
        {
            cout << "O" << endl;
        }
        else
        {
            for (char ch : res)
            {
                cout << ch;
            }
            cout << endl;
        }
    }
}