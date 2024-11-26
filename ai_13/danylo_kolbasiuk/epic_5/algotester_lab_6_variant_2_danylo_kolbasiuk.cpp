#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
std::string attackers(std::vector<std::string> &board, int x, int y);
int main()
{
    std::vector<std::string> board(8);
    for (int i=0; i<8; i++)
    {
        std::cin >> board[i];
    }

    int Q;
    std::cin >> Q;

    std::vector<std::pair<int, int>> coords(Q);
    for (int i=0; i<Q; i++)
    {
        std::cin >> coords[i].first >> coords[i].second;
        coords[i].first--;
        coords[i].second--;
    }
    for (auto &[x, y] : coords) 
    {
        std::cout << attackers(board, x, y) << std::endl;
    }
}
std::string attackers(std::vector<std::string> &board, int x, int y)
{
    if (board[x][y]!='O')
    {
        return "X";
    }
    std::set<char> attack;
    if(x>0) // Pawn
    {
        if (y>0 && board[x-1][y-1] == 'P') attack.insert('P'); 
        if (y<7 && board[x-1][y+1] == 'P') attack.insert('P');
    }

    std::vector<std::pair<int,int>> knight = {{-2, -1}, {2, -1}, {-2, 1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}}; // Knight

    for (auto [one, two] : knight)
    {
        int onen = x+one;
        int twon = y+two;
        if (onen >= 0 && onen < 8 && twon >= 0 && twon < 8 && board[onen][twon]=='N')
        {
            attack.insert('N');
        }
    }

    for(int i = 1; x+i < 8 && y+i < 8; i++) // Bishop (and diagonal attacks of the Queen)
    {
        if (board[x+i][y+i] == 'B' || board [x+i][y+i] == 'Q') attack.insert(board[x+i][y+i]);
    } 
    for(int i = 1; x+i < 8 && y-i >= 0; i++) 
    {
        if (board[x+i][y-i] == 'B' || board [x+i][y-i] == 'Q') attack.insert(board[x+i][y-i]);
    }   
    for(int i = 1; x-i >= 0 && y+i < 8; i++)
    {
        if (board[x-i][y+i] == 'B' || board [x-i][y+i] == 'Q') attack.insert(board[x-i][y+i]);
    }
    for(int i = 1; x-i >= 0 && y-i >= 0; i++) 
    {
        if (board[x-i][y-i] == 'B' || board [x-i][y-i] == 'Q') attack.insert(board[x-i][y-i]);
    }


    for (int i = x-1; i >= 0; i--) // Rook
    {
        if (board[i][y] == 'R' || board[i][y]== 'Q') attack.insert(board[i][y]);
    }
    for (int i = x+1; i < 8; i++)
    {
        if (board[i][y] == 'R' || board[i][y]== 'Q') attack.insert(board[i][y]);
    }
    for (int i = y-1; i >= 0; i--) 
    {
        if (board[x][i] == 'R' || board[x][i]== 'Q') attack.insert(board[x][i]);
    }
    for (int i = y+1; i < 8; i++) 
    {
        if (board[x][i] == 'R' || board[x][i]== 'Q') attack.insert(board[x][i]);
    }

    for (int i=-1; i<=1; i++) // King
    {
        for (int j=-1; j<=1; j++)
        {
            if(i==0 && j==0) continue;
            int onen = x+i;
            int twon = y+j;
            if(onen >= 0 && onen < 8 && twon >= 0 && twon < 8 && board[onen][twon]=='K') 
            {
                attack.insert('K');
            }
        }
    }
    if (attack.empty()) 
    {
        return "O";
    }
    else 
    {
        return std::string (attack.begin(), attack.end());
    }
}