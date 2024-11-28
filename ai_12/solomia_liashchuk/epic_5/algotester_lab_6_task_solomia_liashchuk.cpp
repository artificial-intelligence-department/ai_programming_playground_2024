#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>

using namespace std;

vector<int> findPossibleValues(vector<vector<int>> &board, int rowIdx, int colIdx, int size)
{   
    vector<int> possibleValues;

    if(board[rowIdx][colIdx] != 0)
    {   
        possibleValues.push_back(board[rowIdx][colIdx]);
        return possibleValues;
    }

    set<int> restrictedValues;

    for(int i = 0; i < size; i++)
    {
        if(board[i][colIdx] != 0)
        {
            restrictedValues.insert(board[i][colIdx]);
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(board[rowIdx][i] != 0)
        {
            restrictedValues.insert(board[rowIdx][i]);
        }
    }

    for(int i = 1; i <= size; i++)
    {
        if(restrictedValues.find(i) == restrictedValues.end())
        {
            possibleValues.push_back(i);
        }
    }

    return possibleValues;
}

int main()
{
    int N, Q, x, y;
    string rowData;
    cin >> N;

    if(N < 1 || N > 9)
    {
        return 0;
    }

    vector<vector<int>> board(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {   
        cin >> rowData;
        
        if(rowData.length() != N)
        {
            return 0;
        }
        
        for(int j = 0; j < N; j++)
        {
            board[i][j] = rowData[j] - '0';
            
            if(board[i][j] < 0 || board[i][j] > 9)
            {       
                return 0;
            }
        }
    }

    cin >> Q;

    if(Q < 1 || Q > 1000)
    {
        return 0;
    }

    vector<pair<int, int>> queries;
    for(int i = 0; i < Q; i++)
    {
        cin >> x >> y;
        queries.push_back({x - 1, y - 1});
    }

    for(const auto& query : queries)
    {
        int row = query.first;
        int col = query.second;

        vector<int> possibleValuesList = findPossibleValues(board, row, col, N);
        
        cout << possibleValuesList.size() << endl;

        for(int val : possibleValuesList)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
