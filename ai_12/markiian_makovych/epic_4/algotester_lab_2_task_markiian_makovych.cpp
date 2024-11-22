#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int r[N] = {};
    vector<int> newArr = {};
    vector<int> sumArr = {};

    for (int i = 0; i < N; i++)
    {
        cin >> r[i];
    }
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < N; i++)
    {

        if (r[i] != a && r[i] != b && r[i] != c)
        {
            newArr.push_back(r[i]);
        }
    }
    if (newArr.size() == 0 || newArr.size() == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < newArr.size() - 1; i++)
    {
        sumArr.push_back(newArr[i] + newArr[i + 1]);
    }

    cout << sumArr.size() << endl;
    for (int i = 0; i < sumArr.size(); i++)
    {
        cout << sumArr[i] << " ";
    }
    return 0;
}