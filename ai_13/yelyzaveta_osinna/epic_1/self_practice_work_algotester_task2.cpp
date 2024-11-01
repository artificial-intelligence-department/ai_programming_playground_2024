#include <iostream>
#include <cmath>

using namespace std;

int destination(int x1, int y1, int x2, int y2)
{
    int x = x2 - x1;
    int y = y2 - y1;
    int NumberOfKm = round(sqrt(x * x + y * y));
    return NumberOfKm;
}

int main()
{
    int n;
    cin >> n;
    
    int sum = 0;
    
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sum += destination(x1, y1, x2, y2);
    }
    cout << sum;
    
    return 0;
}