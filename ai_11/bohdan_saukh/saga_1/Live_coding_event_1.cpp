#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

const double variant = 22;

double function_1(){

    int r;
    
    double a, b, c, d, e, f;

    cin >> a >> b >> c >> d >> e >> f;

    double arr[6] = {(double)a, (double)b, (double)c, (double)d, (double)e, (double)f};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);

    
    if ((arr[3] + arr[4] + arr[5]) > (arr[2] + arr[1] + arr[0])*2){
        return ((arr[3] + arr[4] + arr[5]) * (arr[2] + arr[1] + arr[0])) / variant;
    }else if ((arr[3] + arr[4] + arr[5]) > (arr[2] + arr[1] + arr[0])*3){
        return ((arr[3] + arr[4] + arr[5]) / (arr[2] + arr[1] + arr[0])) / variant;
    }else if ((arr[3] + arr[4] + arr[5]) > (arr[2] + arr[1] + arr[0])*4){
        return ((arr[3] + arr[4] + arr[5]) + (arr[2] + arr[1] + arr[0])) / variant;
    }else{
        return 0;
    }


}

double function_2(int a){
    double matrix[5][5];
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            random_device seed;
            mt19937 gen{seed()};
            uniform_int_distribution<> dist{1, 100};
            matrix[i][j] = a + variant + i + j + dist(gen);
        } 
    }  


}    

int main(){
    double x;
    double y;
    x = function_1();
    cout << x;
    y = function_2(x);
    return 0;
}    