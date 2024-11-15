#include <iostream>
#include <vector>

using namespace std;

long findMax(const vector<long>& heights)
{
    long maxVal = heights[0];
    for (int i = 1; i < 4; ++i)
    {
        if (heights[i] > maxVal)
        {
            maxVal = heights[i];
        }
    }
    return maxVal;
}

long findMin(const vector<long>& heights)
{
    long minVal = heights[0];
    for (int i = 1; i < 4; ++i)
    {
        if (heights[i] < minVal)
        {
            minVal = heights[i];
        }
    }
    return minVal;
}

int main()
{
    vector<long> heights(4);
    vector<long> cuts(4);

    for (auto& height : heights)
    {
        cin >> height;
    }

    for (int i = 0; i < 4; ++i)
    {
        cin >> cuts[i];

        if (heights[i] < cuts[i])
        {
            cout << "ERROR";
            return 0;
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        heights[i] -= cuts[i];
        
        if (findMax(heights) >= 2 * findMin(heights))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
