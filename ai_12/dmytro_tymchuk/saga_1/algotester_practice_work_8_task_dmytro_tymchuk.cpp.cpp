///2141
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n, t;
    int arr[100];

    cin>>n>>t;
    cin>>arr[0];

    int s = 0;
    for (int i = 1; i < n; i++)
    {
        cin>>arr[i];
        s += abs(arr[i] - arr[i - 1]) * t;
    }
    
    cout<<s;

    return 0;
}