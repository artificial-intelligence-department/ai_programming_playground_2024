#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

struct point
{
    char name;
    int x;
    int y;
};

bool x_case(vector<point> &v, int x, int y)
{
    for (auto t : v)
        if (t.x == x && t.y == y)
            return true;
    return false;
}

char check(point p, int x, int y)
{
    switch (p.name)
    {
    case 'P':
        if (x - p.x == 1 && abs(y - p.y) == 1)
            return 'P';
        break;
    case 'R':
        if (p.x == x || p.y == y)
            return 'R';
        break;
    case 'N':
        if ((abs(p.x - x) == 1 && abs(p.y - y) == 2) || (abs(p.x - x) == 2 && abs(p.y - y) == 1))
            return 'N';
        break;
    case 'B':
        if (abs(p.x - x) == abs(p.y - y))
            return 'B';
        break;
    case 'K':
        if (abs(p.x - x) <= 1 && abs(p.y - y) <= 1)
            return 'K';
        break;
    case 'Q':
        if ((p.x == x || p.y == y) || (abs(p.x - x) == abs(p.y - y)))
            return 'Q';
        break;
    default:
        break;
    }
    return 'O';
}

int main()
{
    vector<string> s(8);
    vector<point> v;
    for (int i = 0; i < 8; i++)
    {
        getline(cin, s[i]);
        for (int j = 0; j < 8; j++)
            if (s[i][j] != 'O')
                v.push_back({s[i][j], i, j});
    }

    int q;
    cin >> q;
    cin.ignore();
    vector<string> answers;

    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        x = x - 1;
        y = y - 1;

        string answer;
        if (x_case(v, x, y))
            answer = "X";
        else
        {
            for (auto p : v)
            {
                const char el = check(p, x, y);
                if (el != 'O')
                    answer.push_back(el);
            }
            if (answer.size() == 0)
                answer.push_back('O');
        }
        sort(answer.begin(), answer.end());
        answer.erase(unique(answer.begin(), answer.end()), answer.end());
        answers.push_back(answer);
    }

    for (auto a : answers)
        cout << a << endl;

    return 0;
}





