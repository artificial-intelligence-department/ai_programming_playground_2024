#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> oddNums, evenNums;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if(arr[i] % 2 ==0)
        {
            evenNums.push_back(arr[i]);
        }
        else
        {
            oddNums.push_back(arr[i]);
        }
    }

    if(abs((int)evenNums.size() - (int)oddNums.size()) > 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> f;

    if(evenNums.size() >= oddNums.size())
    {
        for(int i = 0; i < evenNums.size(); i++)
        {
            f.push_back(evenNums[i]);
            if(i < oddNums.size())
            f.push_back(oddNums[i]);
        }
    }

    else
    {
        for(int i = 0; i < oddNums.size(); i++)
        {
            f.push_back(oddNums[i]);
            if(i < evenNums.size())
            f.push_back(evenNums[i]);
        }
    }
    

    for(int num : f)
    {
        cout << num << " ";
        cout << "\n";
    }

    return 0;
}