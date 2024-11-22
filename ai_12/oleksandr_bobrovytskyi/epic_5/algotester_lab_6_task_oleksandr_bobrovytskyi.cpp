#include<bits/stdc++.h>

using namespace std;

vector<int> PossibleValues(vector<vector<int>> &v1, int x, int y, int n)
{   
    vector<int> result;
    if(v1[x][y] != 0)
    {   
        result.push_back(v1[x][y]);
        return result;
    }

    set<int> ForbiddenValues;

    for(int i = 0; i < n; i++)
    {
        if(v1[i][y] != 0)
        {
            ForbiddenValues.insert(v1[i][y]);
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        if(v1[x][i] != 0)
        {
            ForbiddenValues.insert(v1[x][i]);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(ForbiddenValues.find(i) == ForbiddenValues.end())
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    int N, Q, x, y = 0;
    string row;
    cin >> N;
    if(N > 9 || N < 1)
    {
        return 0;
    }

    vector<vector<int>> v1(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {   
        cin >> row;
        if(row.length() != N)
        {
            return 0;
        }
        for(int j = 0; j < N; j++)
        {
            v1[i][j] = row[j] - 48;
            if(v1[i][j] > 9 || v1[i][j] < 0)
            {       
                return 0;
            }
        }
    }

    cin >> Q;

    if(Q > 1000 || Q < 1)
    {
        return 0;
    }

    vector<pair<int, int>> position;
    for(int i = 0; i < Q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        position.push_back({x, y});
    }

    for(int i = 0; i < Q; i++)
    {
        vector<int> possible = PossibleValues(v1, position[i].first, position[i].second, N);
        int s = possible.size();
        cout << s << endl;
        for(int j = 0; j < s; j++)
        {
            cout << possible[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
