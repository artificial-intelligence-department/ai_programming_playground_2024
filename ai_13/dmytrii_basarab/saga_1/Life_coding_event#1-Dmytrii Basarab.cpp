#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;
double function_1() {
    double a,b;
    int c,d,e;
    float f; 
    cin >> a >> b >> c  >> d  >> e  >> f;
    double arr[6]={a,b,c,d,e,f};



int n = sizeof(arr) / sizeof(arr[0]);
sort(arr, arr+n);

    double summin = arr[0]+arr[1]+arr[2];
    double summax = arr[3]+arr[4]+arr[5];

if (summax > summin*2) {
    return summax*summin;
} else if (summax > summin*3) {
    return summax / summin;
}  else if (summax > summin*4) {
    return summax + summin;
} else {
    return 1;
}


}

double function_2(double& x) {
        srand(time(0));
    double arr2[5][5] = {x};
    for (int i = 0; i < 4; i++)
    {
       for (int j = 0; j < 4; j++)
       {
        arr2[i][j] = (arr2[i][j]+59+j-i)*(rand()%100)+1;
       }
       
    }
    
    for (int i = 0; i < 4; i++)
    {
       for (int j = 0; j < 4; j++)
       {
        cout << arr2[i][j];
       }
    }

    return arr2[5][5];
}

double function_3(arr2[][]) {
    arr3[5];
    for (int j = 0; j < 4; j++){
       for (int i = 0; i < 4; i++){
        int n = sizeof(arr[i][j]) / sizeof(arr[0]);
        sort(arr2, arr+n);
        arr3[0]=arr[0][j];
       }  
    }
    return arr3;
}
int main() {
    const int var = 59;
    double x = function_1();
double arr2[5][5] = function_2(x);

 function_3(arr2[][]);
}