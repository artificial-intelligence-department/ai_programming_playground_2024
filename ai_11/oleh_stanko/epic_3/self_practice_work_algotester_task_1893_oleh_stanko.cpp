#include <iostream>

using namespace std;

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;
    int s = 0;

    for (int i = 0; i < n; i++) 
    {
        string si;
        cin >> si;
        int ni=0;
        for (int j=0;j<m;j++)
        {
            if (si[j]=='*')
            {
                ni++;
            }
        }
        
        if (ni % k != 0) 

        {
            s += ni / k + 1;
        }
        else 
        {
            s += ni / k;
        }
        ni=0;
    }

    cout << s << endl;
    return 0;
}
