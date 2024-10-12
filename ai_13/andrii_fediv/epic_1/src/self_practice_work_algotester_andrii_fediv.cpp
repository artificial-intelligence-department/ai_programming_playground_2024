#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    string pre_n;
    getline(cin, pre_n);
    istringstream stream1(pre_n);
    int n;
    stream1 >> n;

    string str_arr;
    vector<int> arr;
    getline(cin, str_arr);
    istringstream stream2(str_arr);
    int number;
    while (stream2 >> number)
    {
        arr.push_back(number);
    }

    vector<int> sequences(n, 1);

    for (int r = 1; r < n; r++)
    {
        for (int l = 0; l < r; l++)
        {
            if (arr[r] > arr[l] && sequences[r] < sequences[l] + 1)
            {
                sequences[r] = sequences[l] + 1;
            }
        }
    }

    int acc = 1;
    for (int el : sequences)
    {
        if (acc < el)
        {
            acc = el;
        }
    }
    cout << acc;

    return 0;
}