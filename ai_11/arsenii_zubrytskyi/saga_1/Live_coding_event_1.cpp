#include <iostream>
#include <algorithm>


using namespace std;

double function_1(){
    float a, b;
    int c, d , e;
    double f;
    const int variant = 9; 
    double x;

    cin >> a >> b >> c >> d >> e >> f;

    double arr[6] = {a, b, c, d, e, f};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[j] > arr[j + 1]) { 
                std::swap(arr[j], arr[j + 1]); 
            }
        }
    }

    if(arr[5]+arr[4]+arr[3] > 2*(arr[0] + arr[1] + arr[2])){
        x = ((((arr[5]+arr[4]+arr[3]) * (arr[0] + arr[1] + arr[2])))/variant);
        cout << x << endl;
    }else if(arr[5]+arr[4]+arr[3] > 3*(arr[0] + arr[1] + arr[2])){
        x = ((arr[5]+arr[4]+arr[3]) / (arr[0] + arr[1] + arr[2]))/variant;
        cout << x << endl;
    }else if(arr[5]+arr[4]+arr[3] > 4*(arr[0] + arr[1] + arr[2])){
        x = (((arr[5]+arr[4]+arr[3]) + (arr[0] + arr[1] + arr[2])))/variant;
        cout << x << endl;
    }
    return x;
}





int main(){

function_1();


return 0;
}