#include <iostream>
#include <vector>
using namespace std;

// lab 3v1
int main()
{
    short n;
    cin >> n;
    cin.ignore();
    vector<string> arr(n);
    for (auto &el : arr)
    {
        getline(cin, el);
    }

    long long count = 0;
    for (int j = 0; j < n; j++)
    {
        for (size_t i = 0; i < arr[j].length(); i++)
        {
            if (i == arr[j].length() - 1 && arr[j][i] == '#')
            {
                count++;
            }
            else if (arr[j][i - 1] == '#' && arr[j][i] != '#')
            {
                count++;
            }
        }
    }


    cout << count;

    return 0;
}