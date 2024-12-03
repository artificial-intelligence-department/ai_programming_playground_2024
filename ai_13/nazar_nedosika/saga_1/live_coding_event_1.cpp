#include <iostream>


using namespace std;

double function1(){
    int c, d, e;
    double a, b, f;

    cin >> c >> d >> e;
    cin >> f >> a >> b;

    double values[6] = {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), f};

    int variant = 74;
    double max1 = values[0], max2 = values[1], max3 = values[2];
    double min1 = values[0], min2 = values[1], min3 = values[2];
    int maxs = max1 + max2 + max3;
    int mins = min1 + min2 + min3;
    int result;

    cout << max1;

    if(maxs > mins * 2){
        result = maxs * mins;
    }
    else if(maxs > mins * 3){
        result = maxs/mins;
    }
    else if(maxs > mins * 4){
        result = maxs + mins;
    }

    result = result / variant;
    return result;
}

void function2(double& x, double matrix[5][5]){
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; i <= 5; i++)
        {
            matrix[i][j] = x;
        }
    }
}

int main(){
    double x = function1();
    double matrix[5][5];

    function2(x, matrix);
    cout << x;

    return 0;
}