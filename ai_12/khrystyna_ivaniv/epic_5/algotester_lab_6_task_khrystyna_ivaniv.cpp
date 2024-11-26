#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

struct Figure
{
    char name;
    int x;
    int y;
};

const char figures_type[] = {'P', 'R', 'N', 'B', 'K', 'Q', 'X', 'O'};

int cell_check(Figure &f, int x, int y)
{
    if (f.x == x && f.y == y)
        return 6;
    switch (f.name)
    {
    case 'P':
        if (f.x == x - 1 && abs(f.y - y) == 1)
            return 0;
        break;
    case 'R':
        if (f.x == x || f.y == y)
            return 1;
        break;
    case 'N':
        if ((abs(f.x - x) == 2 && abs(f.y - y) == 1) || (abs(f.x - x) == 1 && abs(f.y - y) == 2))
            return 2;
        break;
    case 'B':
        if (abs(f.x - x) == abs(f.y - y))
            return 3;
        break;
    case 'K':
        if (abs(f.x - x) <= 1 && abs(f.y - y) <= 1)
            return 4;
        break;
    case 'Q':
        if (f.x == x || f.y == y || abs(f.x - x) == abs(f.y - y))
            return 5;
        break;
    default:
        break;
    }
    return -1;
}

int main(){

  vector<vector<char>> answer;
    vector<Figure> figures;
    for (int i = 0; i < 8; i++)
    {
        string row;
        cin >> row;
        for (int i1 = 0; i1 < row.size(); i1++)
        {
            if (row[i1] != figures_type[7])
            {
                Figure figure = {row[i1], i + 1, i1 + 1};
                figures.push_back(figure);
            }
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        set<char> result;
        int x, y;
        cin >> x >> y;
        bool case1 = true;
        bool case2 = false;

        for (auto &figure : figures)
        {
            int index = cell_check(figure, x, y);
            if (index <= 5 && index !=-1)
            {
                result.insert(figures_type[index]);
                case1 = false;
            } 
            else if (index == 6){
                case1 = false;
                case2 = true;
            }
        }
        if (case2)
        {
            answer.push_back(vector<char>(1, figures_type[6]));
        }
        else if (case1)
        {
            answer.push_back(vector<char>(1, figures_type[7]));
        }
        else
        {
            vector<char> case3;
            for (auto &el : result)
            {
                case3.push_back(el);
            }
            answer.push_back(case3);
        }
    }

    for (auto el1: answer)
    {
        for(auto el2: el1){
            cout << el2;
        }
        cout << endl;
    }
    

    return 0;
}