#include<bits/stdc++.h>

using namespace std;
vector<string> board(8);

bool could_king(int x, int y) {
    if (((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7)) && (board[x][y] == 'K'))
        return true;
    else
        return false;
}

bool king(int x, int y) {
    vector<pair<int, int>> offset = {{1,  0},
                                     {1,  1},
                                     {1,  -1},
                                     {-1, 0},
                                     {-1, 1},
                                     {-1, -1},
                                     {0,  1},
                                     {0,  -1}};
    bool flag = false;
    for (int i = 0; i < 8; i++)
        if (could_king(x + offset[i].first, y + offset[i].second))
            flag = true;
    return flag;
}

bool tyra(int x, int y) {
    bool flag = false;
    for (int i = 0; i < 7; i++)
        if ((board[x][i] == 'R') || (board[i][y]) == 'R')
            flag = true;
    return flag;
}

bool could_slon(int x, int y) {
    if (((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7)) && (board[x][y] == 'B'))
        return true;
    else
        return false;
}

bool slon(int x, int y) {
    bool flag = false;
    vector<pair<int, int>> offset = {{1,  1},
                                     {1,  -1},
                                     {-1, 1},
                                     {-1, -1}};
    for (int i = -7; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            if (could_slon(x + i * offset[j].first, y + i * offset[j].second))
                flag = true;
        }
    }
    return flag;
}

bool could_horse(int x, int y) {
    if (((0 <= x) && (x <= 7) && (0 <= y) && (y <= 7)) && (board[x][y] == 'N'))
        return true;
    else
        return false;
}

bool horse(int x, int y) {
    bool flag = false;
    vector<pair<int, int>> offset = {{2,  1},
                                     {2,  -1},
                                     {-2, 1},
                                     {-2, -1},

                                     {1,  2},
                                     {1,  -2},
                                     {-1, 2},
                                     {-1, -2}};
    for (int i = 0; i < 8; i++) {
        if (could_horse(x + offset[i].first, y + offset[i].second))
            flag = true;
    }
    return (flag);
}

bool pishak(int x, int y) {
    if (((0 <= x - 1) && (0 <= y - 1) && (board[x - 1][y - 1] == 'P')) ||
        ((0 <= x - 1) && (y + 1 <= 7) && (board[x - 1][y + 1] == 'P')))
        return true;
    else
        return false;
}

string find_result(int x, int y) {
    string result = "";
    if (slon(x, y)) result += "B";
    if (king(x, y)) result += "K";
    if (horse(x, y)) result += "K";
    if (pishak(x, y)) result += "P";
    if (slon(x, y) || tyra(x, y)) result += "Q";
    if (tyra(x, y)) result += "R";
    return result;
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    cin;
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        if(board[x-1][y-1]!='O')
            cout<<board[x-1][y-1]<<endl;
        string rez=find_result(x-1,y-1);
        if(rez=="")
            cout<<"O"<<endl;
        else
            cout<<rez<<endl;
    }
}