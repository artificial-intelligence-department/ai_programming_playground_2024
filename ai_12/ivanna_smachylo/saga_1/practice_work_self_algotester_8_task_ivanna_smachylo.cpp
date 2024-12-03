#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

struct coordinate 
{
    int X, Y;
};

double distance(int X1, int Y1, int X2, int Y2)
{
    return sqrt(static_cast<double>(pow(X1 - X2, 2) + pow(Y1 - Y2, 2)));
}

int main()
{
    coordinate r;
    cin >> r.X >> r.Y;
    
    int n, k;
    cin >> n >> k;
    
    coordinate point[1000];
    double Distance[1000];
    
    for(int i = 0; i < n; i++)
    {
        cin >> point[i].X >> point[i].Y;
    }
    
    for(int i = 0; i < n; i++)
    {
        Distance[i] = distance(r.X, r.Y, point[i].X, point[i].Y);
    }
    
    sort(Distance, Distance + n);
    cout << setprecision(13) << Distance[k - 1];
    return 0;
}