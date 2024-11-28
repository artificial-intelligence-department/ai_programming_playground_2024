#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr, arrSorted;
    vector<int> divide0, divide1, divide2;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] % 3 == 0)
        {
            divide0.push_back(arr[i]);
        }
        else if (arr[i] % 3 == 1)
        {
            divide1.push_back(arr[i]);
        }
        else if (arr[i] % 3 == 2)
        {
            divide2.push_back(arr[i]);
        }
    }

    sort(divide0.begin(), divide0.end());
    sort(divide2.begin(), divide2.end());
    sort(divide1.begin(), divide1.end(), greater<int>());
    for (int i = 0; i < divide0.size(); i++)
    {
        arrSorted.push_back(divide0[i]);
    }

    for (int i = 0; i < divide1.size(); i++)
    {
        arrSorted.push_back(divide1[i]);
    }

    for (int i = 0; i < divide2.size(); i++)
    {
        arrSorted.push_back(divide2[i]);
    }

    cout << arrSorted.size() << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arrSorted[i] << " ";
    }

    return 0;
}