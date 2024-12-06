#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;



double function_1(const int& VAR) {
    float a, b;
    int c, d, e;
    double f;
    cout << "Enter these numbers: ";
    cin >> a >> b >> c >> d >> e >> f;
    double sum_min = 0.0;
    double sum_max = 0.0;
    double numb[6] = {a, b, (double)c, (double)d, (double)e, f};
    sort(numb, numb+6);
    sum_min += numb[3] + numb[4] + numb[5];
    sum_max += numb[0] + numb[1] + numb[2];
    double x;
    if (sum_max > sum_min*2) {
        if (sum_max > sum_min*3) {
            if (sum_max > sum_min*4) {
                x = sum_max + sum_min;
                return (x / (double)VAR);
            }
            x = sum_max / sum_min;
            return (x / (double)VAR);
        }
        x = sum_max * sum_min;
        return (x / (double)VAR);
    }
    return 0.0;
}
double* function_2(double& x, const int& VAR) {
    static double matrix[5][5]= {x};
    int random_num = rand() % 101;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            matrix[row][col] = (x + VAR + col - row) * double(random_num);
            cout << matrix[row][col];
        }

    }
    return matrix;
}
int main() {
    const int VAR = 16;
    double x = function_1(VAR);
    double *tower = function_2(x, VAR);
    
    return 0;
}