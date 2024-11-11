#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int a, b;
    cin >> a >> b;

    int min_val = min(a, b);
    int max_val = max(a, b);

    if (min_val < 7 && max_val > 7) 
    {
        cout << 7 << endl;
    } 
    else if (max_val - min_val > 1) 
    {
        cout << min_val + 1 << endl;
    } 
    else 
    {
        cout << -1 << endl;
    }

    return 0;
}
