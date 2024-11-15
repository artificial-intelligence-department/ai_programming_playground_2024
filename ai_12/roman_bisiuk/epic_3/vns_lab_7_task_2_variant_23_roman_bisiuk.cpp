#include <iostream>
#include <vector>
using namespace std;

void FnOverload(vector<int> &arr, bool t)
{
    int first = arr[0] % arr.size();
    vector<int> temp;
    temp.insert(temp.begin(), arr.begin() + first, arr.end());
    temp.insert(temp.end(), arr.begin(), arr.begin() + first);
    arr = temp;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void FnOverload(vector<int> &arr)
{
    if (arr[0] % 2 == 0)
        FnOverload(arr, true);
    else
    {
        int last = arr[arr.size() - 1] % arr.size();
        vector<int> temp;
        temp.insert(temp.begin(), arr.end() - last, arr.end());
        temp.insert(temp.end(), arr.begin(), arr.end() - last);
        arr = temp;
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {3, 4, 3, 4, 5, 2};
    FnOverload(arr);

    return 0;
}