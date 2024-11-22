#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, temp;
    cin >> n;
    if(n < 1 || n > 100)
    {
        return 1;
    }
    
    vector<int> num1(n);

    for(int i = 0; i < n; i++)
    {
        cin >> num1[i];
        if(num1[i] < 1 || num1[i] > 100)
        {
            return 1;
        }
    }

    sort(num1.begin(), num1.end());

    cin >> m;
    if(m < 1 || m > 100)
    {
        return 1;
    }
    vector<int> num2(m);

    for(int i = 0; i < m; i++)
    {   
        cin >> num2[i];
        if(num2[i] < 1 || num2[i] > 100)
        {
            return 1;
        }
    }

    sort(num2.begin(), num2.end());
    
    vector<int> result;

    set_difference(num1.begin(), num1.end(), num2.begin(), num2.end(), inserter(result, result.begin()));

    cout << result.size() << endl;
    for(auto i : result)
    {
        cout << i << " ";
    }
    cout << "\n\n";

    result.clear();

    set_difference(num2.begin(), num2.end(), num1.begin(), num1.end(), inserter(result, result.begin()));

    cout << result.size() << endl;
    for(auto i : result)
    {
        cout << i << " ";
    }
    cout << "\n\n";
    
    result.clear();

    set_intersection(num1.begin(), num1.end(), num2.begin(), num2.end(), inserter(result, result.begin()));
    
    cout << result.size() << endl;
    for(auto i : result)
    {
        cout << i << " ";
    }
    cout << "\n\n";

    result.clear();

    set_union(num1.begin(), num1.end(), num2.begin(), num2.end(), inserter(result, result.begin()));

    cout << result.size() << endl;
    for(auto i : result)
    {
        cout << i << " ";
    }
    cout << "\n\n";

    result.clear();

    set_symmetric_difference(num1.begin(), num1.end(), num2.begin(), num2.end(), inserter(result, result.begin()));

    cout << result.size() << endl;
    for(auto i : result)
    {
        cout << i << " ";
    }
    cout << "\n\n";

    return 0;
}