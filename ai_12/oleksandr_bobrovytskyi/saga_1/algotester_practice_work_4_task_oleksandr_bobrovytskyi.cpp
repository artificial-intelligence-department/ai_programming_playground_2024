#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,count = 0;
    int min = INT_MAX;

    cin >> n;
    if(n > 1e6 || n < 1)
    {
        return 1;
    }

    vector<int> numbers(n);

    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        if(numbers[i] > 1e9 || numbers[i] < 1)
        {
            return 1;
        }

        if(numbers[i] <= min)
        {
            min = numbers[i];
            count++; 
        }
    }

    cout << count;

    return 0;
}