//Непарний масив
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void numbers(const vector<int>& arr, vector<int>& even, vector<int>& odd)
{
    for(int num : arr)
    {
        if(num % 2 == 0)
        {
            even.push_back(num);
        }
        else
        {
            odd.push_back(num);
        }
    }
}

void vectors(const vector<int>& large, vector<int>& small, vector<int>& result)
{
    for(int i = 0; i < large.size(); i++)
    {
        result.push_back(large[i]);
        if(i < small.size())
        {
            result.push_back(small[i]);
        }
    }
}

void vectors(const vector<double>& large, const vector<double>& small, const vector<double>& result)
{
    for(int i = 0; i < large.size(); i++)
    {
        result.push_back(large[i]);
        if(i < small.size())
        {
            result.push_back(small[i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    numbers(arr, even, odd);

    if(abs((int)even.size() - (int)odd.size()) > 1)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> f;

    if(even.size() >= odd.size())
    {
        vectors(even, odd, f);
    }
    else
    {
        vectors(odd, even, f);
    }

    for(int num : f)
    {
        cout << num << " ";
        cout << "\n";
    }

    return 0;
}