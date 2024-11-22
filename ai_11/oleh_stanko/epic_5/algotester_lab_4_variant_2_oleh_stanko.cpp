#include <iostream>

using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    int a[N];
    for (int i; i<N; i++)
    {
        cin >> a[i];
    }

    for (int i=0; i<N; i++)
    {
        bool is_change = false;
        for (int j=0; j<N-1; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                is_change = true;               
            }
        }
        if (!is_change)
        {
            break;
        }
    }
    
    int j=0;
    for (int i = 0; i < N-1; i++) 
    {
        if (a[i] != a[i+1])
        {
            a[j++] = a[i]; 
        } 
    }
    a[j++] = a[N-1];

    cout << j << endl;

    for (int i = K; i < K+j; i++)
    {
        cout << a[i%j] << " ";
    }
}