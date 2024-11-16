#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n, k;
    
    cin>>n>>k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    auto new_end = unique(arr.begin(), arr.end());
    arr.erase(new_end, arr.end());

    rotate(arr.begin(), arr.begin() + (k % arr.size()), arr.end());
    cout<<arr.size()<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}