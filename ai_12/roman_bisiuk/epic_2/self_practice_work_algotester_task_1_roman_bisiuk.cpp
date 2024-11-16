#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int x_h, y_h, x_g, y_g;
    cin >> x_h >> y_h;
    cin >> x_g >> y_g;
    if(x_h <= 0 && x_h >= 10e9 && y_h <= 0 && y_h >= 10e9 &&x_g <= 0 && x_g >= 10e9 && y_g <= 0 && y_g >= 10e9 ){
        return 0;
    }

    int distance_x = abs(x_h - x_g);
    int distance_y = abs(y_h - y_g);    

    int totalTime = distance_x + distance_y;
    cout << totalTime;

    return 0;
}