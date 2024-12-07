#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

double function_1(){
    float a, b;
    int c, d, e;
    double f;
    double values[6];
    double x;
    const int variant = 8;

    cin >> a >> b >> c >> d >> e >> f;

    values[0] = a;
    values[1] = b;
    values[2] = c;
    values[3] = d;
    values[4] = e;
    values[5] = f;

    for (int i = 0; i < 5; i++){
        for (int j = i + 1; j < 6; j++){
            if (values[i] > values[j]){
                double elem = values[i];
                values[i] = values[j];
                values[j] = elem;
            }
        }
    }

    double min_sum = values[0] + values[1] + values[2];
    double max_sum = values[3] + values[4] + values[5];

    if (max_sum > (min_sum * 2)){
        x = max_sum * min_sum;
    }
    else if (max_sum > (min_sum * 3)){
        x = max_sum / min_sum;
    }
    else if (max_sum > (min_sum * 4)){
        x = max_sum + min_sum;
    }

    x /= variant;
    cout << x << endl;
    return x;
}

double function_2(double &x){
    const int variant = 8;
    double matrix[5][5] = {x};

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            srand(time(0));
            matrix[i][j] = (matrix[i][j] + variant + j - i) * (rand()%100 + 1);
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << matrix[i][j] << endl;
        }
    }

    return matrix;
}

int main(){
    double x = function_1();
    double result = function_2(x);

    return 0;
}