#include <iostream>

using namespace std;

int main() 
{
    int n, m;
    cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    cin >> m;
    int b[m]; 
    for (int i = 0; i < m; i++) 
    {
        cin >> b[i];
    }

    int Same = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (a[i] == b[j]) 
            {
                Same++;
                break;
            }
        }
    }
    cout << Same << endl;

    bool unique[201] = {false}; 
    for (int i = 0; i < n; i++) 
    {
        unique[a[i]] = true;
    }
    for (int i = 0; i < m; i++) 
    {
        unique[b[i]] = true;
    }

    int count = 0;
    for (int i = 0; i <= 100; i++) 
    {
        if (unique[i]) 
        {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}