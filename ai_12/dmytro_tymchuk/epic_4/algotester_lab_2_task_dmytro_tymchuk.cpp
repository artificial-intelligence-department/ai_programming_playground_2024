#include<iostream>
using namespace std;

int bubble_sort( int *arr, int len)
{
    int change;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] > arr[j])
            {
                change = arr[i];
                arr[i]=arr[j];
                arr[j]=change;
            }
        }
    }
    
    return 0;
}


int main()
{
    int n;
    int arr[100000];

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    bubble_sort(arr,n);

    if (n == 1) cout<<0<<endl;
    else if (arr[n-1] - arr[1] < arr[n-2] - arr[0]) cout<<arr[n-1] - arr[1]<<endl;
    else cout<<arr[n-2] - arr[0]<<endl;

    return 0;
}