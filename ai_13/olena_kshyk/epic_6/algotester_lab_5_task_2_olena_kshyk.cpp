#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> cave(n);
    cin.ignore();
    
    for (int i = 0; i < n; i++)
        getline(cin, cave[i]);

    for (int i = 0; i < m; i++)
        for (int j = n - 1; j >= 0; j--)
            if (cave[j][i] == 'S')
                for (int k = j + 1; k < n; k++)
                    if (cave[k][i] == 'O')
                        swap(cave[k][i], cave[k - 1][i]);
                    else
                        break;

    cout <<"\n";
    for (int i = 0; i < n; i++)
       cout << cave[i] << endl;
    
    return 0;
}