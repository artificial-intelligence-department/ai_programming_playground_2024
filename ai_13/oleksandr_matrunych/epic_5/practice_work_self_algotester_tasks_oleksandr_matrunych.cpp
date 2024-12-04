#include <iostream>
#include <vector>

using namespace std;
using vint = vector<int>;
using ving = vector<char>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ving> arr(m);
    for (size_t i1 = 0; i1 < n; i1++)
    {
        string v;
        cin >> v;
        for (size_t i2 = 0; i2 < m; i2++)
            arr[i2].push_back(v[i2]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int i1 = arr[0].size() - 1; i1 >= 0; i1--)
        {

            if (arr[i][i1] == 'S')
            {
                int acc = arr[i].size() - 1;
                for (size_t i2 = i1 + 1; i2 < n; i2++)
                {
                    if (arr[i][i2] == 'X' || arr[i][i2] == 'S')
                    {
                        arr[i][i1] = 'O';
                        arr[i][i2 - 1] = 'S';
                        acc = -1;
                        break;
                    }
                }
                if (acc != -1)
                {
                    arr[i][i1] = 'O';
                    arr[i][acc] = 'S';
                }
            }
        }
    }
    cout << '\n';
    for (size_t i1 = 0; i1 < n; i1++)
    {
        for (size_t i2 = 0; i2 < m; i2++)
            cout << arr[i2][i1];
        cout << '\n';
    }

    return 0;
}

/*5 5
SSOSS
OOOOO
SOOXX
OOOOS
OOSOO

*/