#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int var = 19;
const int N = 5;

float function_1(){
    float a, b;
    int c, d, e;
    double f;
    cin >> a >> b >> c >> d >> e >> f;

    double nums[6] = {a, b, c, d, e, f};
    sort(nums, nums+6);

    double top1, top2, top3;
    top1 = nums[6];
    top2 = nums[5];
    top3 = nums[4];

    double min1, min2, min3;
    min1 = nums[0];
    min2 = nums[1];
    min3 = nums[2];

    double x;
    if ((top1+top2+top3) > (min1+min2+min3) * 2){
        x = (top1+top2+top3) * (min1+min2+min3);
    } else if ((top1+top2+top3) > (min1+min2+min3) * 3){
        x = (top1+top2+top3) / (min1+min2+min3);
    } else if ((top1+top2+top3) > (min1+min2+min3) * 4){
        x = (top1+top2+top3) / (min1+min2+min3);
    }
    x /= var;
    cout << x;

    return x;
}

double** function_2(double x){
    double** arr = new double *[N];
    for(int i = 0; i < 5; i++){
        arr[i] = new double[N]; 
        for(int j = 0; j < 5; j++){
            arr[i][j] = x;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int randint = rand() % 100 + 1;
            arr[i][j] = ((x + 19 + i - j) * randint);
            cout << arr[i][j];
        }
    }
    return arr;
}

double function_3(tower[N][N]);

int main(){
    double x = function_1();
    double** tower = function_2(x);
    function_3(tower);


    return 0;
}