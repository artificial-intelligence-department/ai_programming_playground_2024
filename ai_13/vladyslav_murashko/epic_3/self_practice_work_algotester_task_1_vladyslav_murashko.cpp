#include <iostream>
#include <vector>

using namespace std;

long getMax(vector<long> heights)
{
    long max = heights[0];
    for (size_t i = 1; i < 4; i++)
    {
        if (heights[i] > max)
        {
            max = heights[i];
        }
    }
    return max;
}

long getMin(vector<long> heights)
{
    long min = heights[0];
    for (size_t i = 1; i < 4; i++)
    {
        if (heights[i] < min)
        {
            min = heights[i];
        }
    }
    return min;
}

// algotester lab 1v2
int main()
{
    vector<long> heights(4);
    vector<long> toCut(4);
    long min;

    for (auto &height : heights)
    {
        cin >> height;
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> toCut[i];
        
        if (heights[i]-toCut[i] < 0)
        {
            cout << "ERROR";
            return 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        heights[i] -= toCut[i];
        if (getMax(heights) >= (getMin(heights) * 2))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
