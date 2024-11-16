#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void print_arr (vector<int>& arr)
{
    cout<<arr.size()<<endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}

int remainder_0(int n)
{
    return n % 3 == 0;
}

int remainder_1(int n)
{
    return n % 3 == 1;
}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    
    auto begin_1 = partition(arr.begin(), arr.end(), remainder_0);
    sort(arr.begin(), begin_1);
    auto index_1 = unique(arr.begin(), begin_1);
    arr.erase(index_1, begin_1);

    auto begin_2 = partition(index_1, arr.end(), remainder_1);
    sort(index_1, begin_2);
    auto index_2 = unique(index_1, begin_2);
    arr.erase(index_2, begin_2);

    sort(index_2, arr.end());
    auto index_3 = unique(index_2, arr.end());
    arr.erase(index_3, arr.end());

    
    

    

    

    sort(index_1, index_2, [](int a, int b) {
        return a > b;  
    });

    print_arr(arr);
    return 0;
}