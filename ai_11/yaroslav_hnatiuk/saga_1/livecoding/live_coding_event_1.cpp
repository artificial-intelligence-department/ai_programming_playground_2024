#include <iostream>
#include <algorithm>
#include <random>

using namespace std;


float function_1();
//void function_2(float x, float tower[5][5]);


int main() {
    double x = function_1();

    cout << x;

    double tower[5][5];
    random_device seed;
    mt19937 gen{seed()};
    uniform_int_distribution<> dist(1, 100);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tower[i][j] = (x + 5 + i + j) * dist(gen);
            cout << tower[i][j];
        }
    }

    return 0;
}


float function_1() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    float arr[6] = {(double) a, (double) b, (double) c, (double) d, (double) e, (double) f};

    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + len);

    if (arr[3] + arr[4] + arr[5] > (arr[0] + arr[1] + arr[2]) * 2) 
        return ((arr[3] + arr[4] + arr[5]) * (arr[0] + arr[1] + arr[2])) / 5;

    else if (arr[3] + arr[4] + arr[5] > (arr[0] + arr[1] + arr[2]) * 3) 
        return ((arr[3] + arr[4] + arr[5]) / (arr[0] + arr[1] + arr[2])) / 5;

    else if (arr[3] + arr[4] + arr[5] > (arr[0] + arr[1] + arr[2]) * 4) 
        return ((arr[3] + arr[4] + arr[5]) + (arr[0] + arr[1] + arr[2])) / 5;
    else 
        return 0;
}

/*
void function_2(float x, float &tower) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tower[i][j] = x;
        }
    }

    return;
}
*/


