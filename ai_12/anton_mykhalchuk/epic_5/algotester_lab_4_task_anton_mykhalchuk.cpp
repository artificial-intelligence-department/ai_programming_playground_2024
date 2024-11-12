#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    auto it = unique(numbers.begin(), numbers.end());
    numbers.resize(distance(numbers.begin(), it));

    k %= numbers.size();
    rotate(numbers.begin(), numbers.begin() + k, numbers.end());

    cout << numbers.size() << endl;

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << ' ';
    }
}