#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

int main()
{
    string s;
    int n, matrix[100][100];
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>s;
        for (int j = 0; j < s.length(); j++)
        {
            matrix[i][j + 1] = (int)s[j] - 48;
        }
    }

    int q, x[100], y[100];
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        cin>>x[i]>>y[i];
    }
    
    
    for (int i = 0; i < q; i++)
    {
        int missing_elements[10]{}, num_of_missing_elements = 0;

        if (matrix[x[i]][y[i]] == 0)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((matrix[x[i]][j] != 0) && (missing_elements[matrix[x[i]][j]] == 0))
                {
                    missing_elements[matrix[x[i]][j]] = 1;
                    num_of_missing_elements++;
                }

                if ((matrix[j][y[i]] != 0) && (missing_elements[matrix[j][y[i]]] == 0)) 
                {
                    missing_elements[matrix[j][y[i]]] = 1;
                    num_of_missing_elements++;
                }
            }

            if (n - num_of_missing_elements == 0) cout<<0;
            else
            {
                int m = 0;

                cout<<n - num_of_missing_elements<<endl;
                for (int j = 1; j <= n; j++)
                {
                    if (missing_elements[j] == 0)
                    {
                        m++;
                        if (m == n - num_of_missing_elements) cout<<j;
                        else cout<<j<<" ";
                    }
                }
            }
            if (i < q - 1) cout<<endl<<endl;
        }
        else 
        {
            printf("%d\n%d", 1, matrix[x[i]][y[i]]);
            if (i < q - 1) cout<<endl<<endl;
        }
    }
    
    return 0;
}