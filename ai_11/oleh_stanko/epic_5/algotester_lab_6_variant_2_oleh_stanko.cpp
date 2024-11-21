#include <iostream>
#include <algorithm> 
#include <string>

using namespace std;

void check_pawn(char figure[8][8], int x, int y, string res[],int i)
{   
    if (x - 1 >= 0) 
    {
        if (y - 1 >= 0 && figure[x - 1][y - 1] == 'P') 
        {
            res[i] += "P";
        }
        if (y + 1 < 8 && figure[x - 1][y + 1] == 'P') 
        {
            res[i] += "P";
        }
    }
}

void check_rook(char c, char figure[8][8], int x, int y, string res[], int i) 
{
    int j = 1;
    while (x - j >= 0 || x + j <= 7 || y - j >= 0 || y + j <= 7) 
    {
        if (x - j >= 0 && figure[x - j][y] == c) 
        {
            res[i] += string(1, c); 
        }
        if (x + j <= 7 && figure[x + j][y] == c) 
        {
            res[i] += string(1, c); 
        }
        if (y - j >= 0 && figure[x][y - j] == c) 
        {
            res[i] += string(1, c); 
        }
        if (y + j <= 7 && figure[x][y + j] == c) 
        {
            res[i] += string(1, c); 
        }
        j++;
    }
}

void check_knight(char figure[8][8], int x, int y, string res[], int i)
{
    if (y-2>=0)
    {
        if (x-1>=0)
        {
            if (figure[x-1][y-2] == 'N')
            {
                res[i] += "N";
            }
        }
        if (x+1<8)
        {
            if (figure[x+1][y-2] == 'N')
            {
                res[i] += "N";
            }
        }
    }
    if (y+2<8)
    {
        if (x-1>=0)
        {
            if (figure[x-1][y+2] == 'N')
            {
                res[i] += "N";
            }
        }
        if (x+1<8)
        {
            if (figure[x+1][y+2] == 'N')
            {
                res[i] += "N";
            }
        }
    }
    if (x-2>=0)
    {
        if (y-1>=0)
        {
            if (figure[x-2][y-1] == 'N')
            {
                res[i] += "N";
            }
        }
        if (y+1<8)
        {
            if (figure[x-2][y+1] == 'N')
            {
                res[i] += "N";
            }
        }
    }
    if (x+1<8)
    {
        if (y-1>=0)
        {
            if (figure[x+2][y-1] == 'N')
            {
                res[i] += "N";
            }
        }
        if (y+1<8)
        {
            if (figure[x+2][y+1] == 'N')
            {
                res[i] += "N";
            }
        }
    }
}

void check_bishop(char c, char figure[8][8], int x, int y, string res[], int i)
{
    int j = 1;
    while (x - j >= 0 || x + j <= 7 || y - j >= 0 || y + j <= 7) 
    {
        if (x - j >= 0 && y - j >= 0 && figure[x - j][y - j] == c) 
        {
            res[i] += string(1, c);
        }
        if (x + j <= 7 && y + j <= 7 && figure[x + j][y + j] == c) 
        {
            res[i] += string(1, c); 
        }
        if (x - j >= 0 && y + j <= 7 && figure[x - j][y + j] == c) 
        {
            res[i] += string(1, c); 
        }
        if (x + j <= 7 && y - j >= 0 && figure[x + j][y - j] == c) {
            res[i] += string(1, c); 
            }
        j++;
    }
}
void check_queen(char figure[8][8], int x, int y, string res[], int i)
{
    check_rook('Q',figure, x, y, res, i);
    check_bishop('Q',figure, x, y, res, i);
}
void check_king(char figure[8][8], int x, int y, string res[], int i)
{
    int moves[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    for (auto &move : moves) {
        int nx = x + move[0];
        int ny = y + move[1];
        if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && figure[nx][ny] == 'K') 
        {
            res[i] += "K";
        }
    }   
}

int main()
{
    char figure[8][8];
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            cin >> figure[i][j];
        }
    }
    int Q;
    cin >> Q;
    int x, y;
    string res[Q]={};
    for (int i=0; i<Q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        if (figure[x][y]!='O')
        {
            res[i]="X";
        }
        else
        {
            check_pawn(figure,x,y,res,i);
            check_rook('R',figure,x,y,res,i);
            check_knight(figure,x,y,res,i);
            check_bishop('B',figure,x,y,res,i);
            check_queen(figure,x,y,res,i);
            check_king(figure,x,y,res,i);
            if (res[i] == "")
            {
                res[i]="O";
            }
        }
    }

    for (int i=0; i<Q; i++)
    {
        sort(res[i].begin(), res[i].end());
        res[i].erase(unique(res[i].begin(), res[i].end()), res[i].end());
        cout << res[i] << endl;
    }
}