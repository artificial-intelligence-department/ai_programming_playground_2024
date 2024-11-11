#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> lenghts(n);

    for (int i = 0; i < n; i++)
    {
        cin >> lenghts[i].first;
        lenghts[i].second = i + 1;
    }

    sort(lenghts.begin(), lenghts.end());

    for (int i = 0; i < n; i++)
    {
        cout << lenghts[i].second << " ";
    }

    cout << endl;

    return 0;
}