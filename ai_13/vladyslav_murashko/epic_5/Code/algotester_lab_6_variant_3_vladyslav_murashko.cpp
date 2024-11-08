#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> findNumbers(const vector<string> &sudoku, const int &x, const int &y)
{
    vector<int> result;
    if (sudoku[x - 1][y - 1] != '0')
    {
        result.push_back(sudoku[x - 1][y - 1] - '0');
        return result;
    }
    set<int> numbers;
    int N = sudoku.size();
    for (size_t i = 0; i < N; i++)
    {
        numbers.insert(sudoku[x - 1][i] - '0');
        numbers.insert(sudoku[i][y - 1] - '0');
    }
    for (size_t i = 1; i < N + 1; i++)
    {
        if (numbers.count(i) == 0)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{

    int N;
    cin >> N;
    vector<string> sudoku(N);
    for (auto &el : sudoku)
    {
        cin >> el;
    }

    int Q, x, y;
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x >> y;
        vector<int> numbers = findNumbers(sudoku, x, y);
        cout << numbers.size() << endl;
        if (numbers.size() != 0)
        {
            for (auto &el : numbers)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }

    return 0;
}