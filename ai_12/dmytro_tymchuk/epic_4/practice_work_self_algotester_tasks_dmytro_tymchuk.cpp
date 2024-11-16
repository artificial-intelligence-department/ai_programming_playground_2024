//Зуби(182)
#include<iostream>
using namespace std;
typedef unsigned int uint;

int main()
{
    uint n, k, arr[100000];

    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    uint max_len = 0, len = 0, i = 0, j = 0;
    while (i < n)
    {
        if (arr[i] >= k)
        {
            j = i;
            len = 0;
            while (arr[j] >= k)
            {
                len++;
                j++;
            }

            if (max_len < len) max_len = len;
            i = j;
        }
        else i++;
    }
    
    cout<<max_len<<endl;
    
    return 0;
}