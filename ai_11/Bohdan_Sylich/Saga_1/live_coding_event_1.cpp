#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
double function_1(int d, int c, int e, double a, double b, double f){
    int fd = d, fc = c, fe = e;
    int const var = 23;
    double fa = a, fb = b;
    double ff = f;
vector<double> v = {fa, fb, ff, static_cast<double>(fd), static_cast<double>(fc), static_cast<double>(fe)};

sort(v.begin(), v.end());

double sum = v[0] + v[1] + v[2] + v[3] + v[4] + v[5];
double sum_l = v[3] + v[4] + v[5];

double res;
if (sum_l > sum*2){ res = sum_l*sum;}
if (sum_l > sum*3){ res = sum_l/sum;}
if (sum_l > sum*4){res = sum_l - sum_l * sum;}

return res/var;
}
double function_2 (double x){
    double Matrix[5][5] = {(x,x,x,x,x), (x,x,x,x,x), (x,x,x,x,x), (x,x,x,x,x), (x,x,x,x,x)};
    srand(time(NULL));
    int rand_n = 1 + rand() % 100;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            Matrix[i][j] =(x+23+i-j)* rand_n;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; i < 5; j++){
            cout << Matrix[i][j] << endl;
        }
    }
    return Matrix[0][0], Matrix[1][1], Matrix[2][2], Matrix[3][3], Matrix[4][4], Matrix[5][5];
}

double function_3 (double arr[5][5]){
    double array[5];
    double res_1[5]
    for (int i = 0; i < 5; i++){
        res_1[i] = min(arr[i],arr[i], arr[i], arr[i],arr[i]);
    }
    double minm[5];
    minm[5] = arr[0]
    for(int i = 0; i < 5; ++i){
    if(arr[i] < minm)
    {
        minm = arr[i];
    }
    for (int i = 0; i < 5; i++){
    if (res_1[i] = minm[i]){cout << "результати обох пошуків співпадають"}
    else {cout << "результати пошуків відрізняються"}
    }
    for (int i = 0; i < 5; i++){
        array[i] = res_1[i];
    }
    return array[0], array[1], array[2], array[3], array[4];
}
}


int main(){
    cout << function_1(1, 2, 3, 4.0, 5.3, 6.7);

    double x = function_1(1,2,3,4.0, 5.3, 6.7);

    double tower[5][5] = function_2(x);
}