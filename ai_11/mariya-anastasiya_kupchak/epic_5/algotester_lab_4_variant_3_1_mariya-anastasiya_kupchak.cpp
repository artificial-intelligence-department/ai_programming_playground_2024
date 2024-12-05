#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() 
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }

    vector<int> mod0, mod1, mod2;
    for (int num : arr) 
    {
        if (num % 3 == 0)
        {
            mod0.push_back(num);
        }
        else if (num % 3 == 1)
        {
            mod1.push_back(num);
        }
        else
        {
            mod2.push_back(num);
        }
    }

    sort(mod0.begin(), mod0.end());
    sort(mod1.rbegin(), mod1.rend());
    sort(mod2.begin(), mod2.end());

    vector<int> result;
    result.insert(result.end(), mod0.begin(), mod0.end());
    result.insert(result.end(), mod1.begin(), mod1.end());
    result.insert(result.end(), mod2.begin(), mod2.end());

    result.erase(unique(result.begin(), result.end()), result.end());

    cout << result.size() << endl;
    for (int num : result) 
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
