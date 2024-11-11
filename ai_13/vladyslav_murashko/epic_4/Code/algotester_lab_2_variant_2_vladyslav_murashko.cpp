#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &el : arr)
    {
        cin >> el;
    }
    vector<int> toDeleteFromArr(3);
    for (int &el : toDeleteFromArr)
    {
        cin >> el;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if (arr[i] == toDeleteFromArr[j])
            {
                arr.erase(arr.begin() + i);
                i--;
                n--;
                break;
            }
        }
    }
    if (arr.size() > 1)
    {
        cout << n - 1 << endl;
        vector<int> resultArr(n - 1);
        for (size_t i = 0; i < n - 1; i++)
        {
            resultArr[i] = arr[i] + arr[i + 1];
        }
        for (int &el : resultArr)
        {
            cout << el << " ";
        }
    }
    else{
         cout << 0 << endl;
    }
}