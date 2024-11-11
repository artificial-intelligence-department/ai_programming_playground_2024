#include <iostream>
#include <cmath>

using namespace std;

int distance (int x1, int y1, int x2, int y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int main(){

    int n;
    cin >> n;

    int result = 0;

    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        result += distance(x1,y1,x2,y2);
    }

    cout << result;

    return 0;
}