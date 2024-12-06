#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;

    if(n < k || n > 3 * k) 
    {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<int> teams(k, 1); 
    n -= k; 

    for(int i = 0; i < k && n > 0; ++i) 
    {
        int add = min(2, n);
        teams[i] += add;
        n -= add;
    }
    for(int size : teams) 
    {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}
