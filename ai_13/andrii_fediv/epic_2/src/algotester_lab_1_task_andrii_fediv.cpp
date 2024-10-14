#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    vector<long long> arr(4);
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    long long min_h, max_h;
    string answer[] = {"YES", "NO", "ERROR"};
    int acc = 0;
    for (size_t i = 0; i < 4; i++)
    {
        long long l;
        cin >> l;
        arr[i] -= l;
        if (arr[i] >= 0)
        {
            max_h = *max_element(arr.begin(), arr.end());
            min_h = *min_element(arr.begin(), arr.end());

            if (max_h >= min_h * 2 || min_h == 0)
            {
                acc = 1;
            }
        }
        else
        {
            acc = 2;
            break;
        }
    }

    cout << answer[acc];

    return 0;
}