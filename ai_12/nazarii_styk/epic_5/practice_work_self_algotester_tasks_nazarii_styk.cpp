#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    int max_length = 0, current_length = 0;

    for (int i = 0; i < n; i++) 
    {
        if (a[i] >= k) 
        {
            current_length++;
            max_length = max(max_length, current_length);
        } 
        else 
        {
            current_length = 0;
        }
    }

    cout << max_length << endl;
    return 0;
}
