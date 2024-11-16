#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// lab 4v2
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (auto &el : arr)
    {
        cin >> el;
    }

    sort(arr.begin(), arr.end());

    auto iter = unique(arr.begin(), arr.end());
    arr.resize(distance(arr.begin(), iter));

    while (K > arr.size())
    {
        K -= arr.size();
    }
    rotate(arr.begin(), arr.begin() + K, arr.end());

    cout << endl
         << arr.size() << endl;
    for (auto &el : arr)
    {
        cout << el << " ";
    }
}