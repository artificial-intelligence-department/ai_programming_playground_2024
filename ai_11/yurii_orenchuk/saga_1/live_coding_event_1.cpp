#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

const int var = 19;
const int N = 5;

struct ArrStruct{
    double arr[N][N];
};

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

ArrStruct function_2(double x){
    ArrStruct var;
    var.arr[N][N];
    for(int i = 0; i < 5; i++){ 
        for(int j = 0; j < 5; j++){
            var.arr[i][j] = x;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int randint = rand() % 100 + 1;
            var.arr[i][j] = ((x + 19 + i - j) * randint);
            cout << var.arr[i][j];
        }
    }
    return var;
}

double function_3(double tower[N][N]){
    double fin_arr[N];
    double min_el = 1000;
    double min_els1[N];
    int n = sizeof(fin_arr) / sizeof(fin_arr[0]);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(min_el > tower[i][j]) {
                min_el = tower[i][j];
                min_els1[i] = min_el;
            }    
        }    
    }
}

int main(){
    double x = function_1();
    ArrStruct ftower = function_2(x);
    double tower[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            tower[i][j] = ftower.arr[i][j];
        }
    }
    return 0;
}