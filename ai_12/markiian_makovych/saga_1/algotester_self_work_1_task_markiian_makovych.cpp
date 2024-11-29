#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int ties, men;
    cin >> ties >> men;
    vector<long long> length(ties);
    double left = 0.0;
    double right = *max_element(length.begin(), length.end());
    double result = 0.0;

    for (int i = 0; i < ties; i++)
    {
        cin >> length[i];
    }

    while (right - left > 1e-7)
    {
        double mid = (left + right) / 2;
        long long count = 0;

        for (long long l : length)
        {
            count += l / mid;
        }

        if (count >= men)
        {
            result = mid;
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    cout.precision(7);
    cout << fixed << result << endl;

    return 0;
}
