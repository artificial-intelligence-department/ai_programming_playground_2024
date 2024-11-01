#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct MaxMin
{
    int max;
    int min;
    int secondMin;
    int secondMax;
};

struct Solution
{
    int result = 0;
    MaxMin maxMin;
};


// lab 2v1
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &el : arr)
    {
        cin >> el;
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    Solution solution;
    solution.maxMin.max = arr[0];
    solution.maxMin.min = arr[0];
    solution.maxMin.secondMax = INT_MIN;
    solution.maxMin.secondMin = INT_MAX;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] <= solution.maxMin.min)
        {
            solution.maxMin.secondMin = solution.maxMin.min;
            solution.maxMin.min = arr[i];
        }
        else if (arr[i] < solution.maxMin.secondMin)
        {
            solution.maxMin.secondMin = arr[i];
        }
        if (arr[i] >= solution.maxMin.max)
        {
            solution.maxMin.secondMax = solution.maxMin.max;
            solution.maxMin.max = arr[i];
        }
        else if (arr[i] > solution.maxMin.secondMax)
        {
            solution.maxMin.secondMax = arr[i];
        }
    }

    if (n == 2)
    {
        cout << solution.maxMin.min;
        return 0;
    }

    solution.result = solution.maxMin.secondMax - solution.maxMin.min <= solution.maxMin.max - solution.maxMin.secondMin
                          ? solution.maxMin.secondMax - solution.maxMin.min
                          : solution.maxMin.max - solution.maxMin.secondMin;

    cout << solution.result;

    return 0;
}