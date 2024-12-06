#include <iostream>

using namespace std;

int main() 
{
    int n,k,x;
    cin >> n >> k >> x;
    int h[n];
    int s=0;
    for (int i = 0; i<n;i++)
    { 
        cin >> h[i];
        if (h[i] > k)
        {
            s++;
            if (s-x>=2)
            {
                cout << "NO";
                return 0;   
            } 
        } 
    }
    cout << "YES";
    return 0;
}