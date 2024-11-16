#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
    const int N = 8;
bool attacks(char piece, int pieceX, int pieceY, int x, int y){
    switch (piece)
    {
    case 'R':
        return pieceX == x || pieceY == y;
    case 'B': 
        return abs(pieceX - x) == abs(pieceY - y);
    case 'N': 
        return (abs(pieceX - x) == 2 && abs(pieceY - y) == 1) || (abs(pieceX - x) == 1 && abs(pieceY - y) == 2);
    case 'P': 
        return pieceX + 1 == x && abs(pieceY - y) == 1;
    case 'K': 
        return abs(pieceX - x) <= 1 && abs(pieceY - y) <= 1;
    case 'Q': 
        return (pieceX == x || pieceY == y) || (abs(pieceX - x) == abs(pieceY - y));
    default: return false;
    }
}
int main(){
    vector<string> board(N);
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    int Q;
    cin >> Q;
    vector<string> result(Q);
    for (int k = 0; k < Q; k++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (board[x][y] != 'O')
        {
            result[k] = "X";
            continue;
        }
        string results;
    for (int i = 0; i < N; i++) 
    {
            for (int j = 0; j < N; j++) 
            {
                char piece = board[i][j];
                if (piece != 'O' && attacks(piece, i, j, x, y)) 
                {
                    bool found = false;
                    for (char c : results)
                    {
                        if (c == piece)
                        {
                            found = true;
                            break;
                        }
                        
                    }
                    if (!found)
                    {
                        results += piece;
                    }
                }
            }
        }

        if (results.empty()) 
        {
            result[k] = "O";
        } else {
            sort(results.begin(), results.end());
            result[k] = results;
        }
    }
    for (const string& results : result)
    {
        cout << results << endl;
    }
    
    return 0;
}
