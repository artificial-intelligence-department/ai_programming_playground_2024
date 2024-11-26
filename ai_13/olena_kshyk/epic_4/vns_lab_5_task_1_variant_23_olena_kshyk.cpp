#include <iostream>
#include <vector>
using namespace std;

void fill2DArray(const vector<int> &arr1d, vector<vector<double>> &arr2d)
{
    int n = arr1d.size();

    for (int col = 0; col < n; col++)
    {
        double targetSum = arr1d[col];
        double currentSum = 0;

        for (int row = 0; row < n; row++)
            if (row == n - 1)
                arr2d[row][col] = targetSum - currentSum;
            else
            {
                double element = (targetSum / n) + (0.1 * (row + 1));
                arr2d[row][col] = element;
                currentSum += element;
            }
    }
}

void print2DArray(const vector<vector<double>> &arr2d)
{
    for (const auto &row : arr2d)
    {
        for (double elem : row)
            cout << elem << "\t";
        cout << endl;
    }
}

int main()
{
    vector<int> arr1d = {5, 8, 10, 7}; 
    int n = arr1d.size();

    vector<vector<double>> arr2d(n, vector<double>(n, 0.0));

    fill2DArray(arr1d, arr2d);

    cout << "Two-dimensional array:\n";
    print2DArray(arr2d);

    return 0;
}
