#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    int x1, x2, y1, y2;

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int oparstion = sqrt(pow(x2 -x1, 2) + pow(y2 - y1, 2));
        sum += oparstion;
    }

    cout << sum << endl;
    
    return 0;
} 