#include <iostream>

using namespace std;

int main()
{
    int k,n;
    cin >> k >> n;
    int c[n];
    for (int i; i<n; i++)
    {
        cin >> c[i];
    }
    for (int i=0; i<n; i++)
    {
        bool is_change = false;
        for (int j=0; j<n-1; j++)
        {
            if (c[j]>c[j+1])
            {
                int temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
                is_change = true;               
            }
        }
        if (!is_change)
        {
            break;
        }
    }
    int s = 0;
    for (int i=0; i<n; i++)
    {
        if (k-c[i]>=0)
        {
            k-=c[i];
            s++;
        }
    }
    cout << s;
}