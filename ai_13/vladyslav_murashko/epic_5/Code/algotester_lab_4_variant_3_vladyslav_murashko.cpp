#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (auto &el : arr)
    {
        cin >> el;
    }
    partition(arr.begin(), arr.end(), [](int x)
              { return x % 3 == 0; });
    int firstNot0Pos;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 3 != 0)
        {
            firstNot0Pos = i;
            break;
        }
    }
    partition(arr.begin() + firstNot0Pos, arr.end(), [](int x)
              { return x % 3 == 1; });
    int firstNot1Pos;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 3 == 2)
        {
            firstNot1Pos = i;
            break;
        }
    }

    sort(arr.begin(), arr.begin() + firstNot0Pos);
    sort(arr.begin() + firstNot0Pos, arr.begin() + firstNot1Pos, greater{});
    sort(arr.begin() + firstNot1Pos, arr.end());

    auto iter = unique(arr.begin(), arr.end());
    arr.resize(distance(arr.begin(), iter));

    cout << endl
         << arr.size() << endl;
    for (auto &el : arr)
    {
        cout << el << " ";
    }
}