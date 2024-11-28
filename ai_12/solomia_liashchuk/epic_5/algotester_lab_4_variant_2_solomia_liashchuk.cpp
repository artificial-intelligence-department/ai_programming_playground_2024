#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    auto it= unique(arr.begin(),arr.end());
    arr.erase(it,arr.end());

    vector<int> mod0, mod1, mod2;
    for(int x : arr) 
    {
        if(x % 3 == 0)
        {
            mod0.push_back(x);
        }
        else if(x % 3 == 1)
        {
            mod1.push_back(x);
        }
        else 
        {
            mod2.push_back(x);
        }
    }

    sort(mod0.begin(), mod0.end());
    sort(mod1.rbegin(), mod1.rend());
    sort(mod2.begin(), mod2.end());

    arr.clear();
    arr.insert(arr.end(), mod0.begin(), mod0.end());
    arr.insert(arr.end(), mod1.begin(), mod1.end());
    arr.insert(arr.end(), mod2.begin(), mod2.end());

    cout<<arr.size()<<endl;
    for(auto i:arr) 
    {
        cout<<i<<" ";
    }
}