#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <time.h>
using namespace std;


int function_1(){
    double k,x;
    double m[6];
    int c,d,e;
    float a,b;
    double f;
    cin >>a>>b>>c>>d>>e>>f;
    m[0] = c;
    m[1] = d;
    m[2] = e;
    m[3] = a;
    m[4] = b;
    m[5] = f;
    sort(m,m+6); //воно буде посортоване по зростанню(спочатку 3 найменші, далі 3 найбільші)
    double s1 = m[0]+m[1]+m[2];
    double s2 = m[3]+m[4]+m[5];  
    if(s1>2*s2){
        x =s1*s2;
        
    }
    else if(s1>3*s2){
        x = s1/s2;
    }
    else if(s1>4*s2){
        x = s1 + s2;
    }
    x/=52;
    cout << x;
    return x;
}

struct demo_1{
   double m[5][5];
   double x[5][5];
};
demo_1 function_2(double &x){
    demo_1 demo;
    srand(time(NULL));
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            demo.m[i][j] = x;

        }
    }
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            demo.m[i][j] = (demo.m[i][j]+52+j-i)*(fabs(rand()%101));
            cout <<demo.m[i][j] <<" ";
            if(i == 0 && j != 0){
                cout<<endl;
            }
        }
    }
    return demo;
}

demo_1 function_3(double tower[][5]){
    double arr1[5];
    double arr2[5];
        for(int k = 0;k<5;k++){
            double min = tower[0][k];
            for(int i = 0;i<4;i++){
                if(tower[i][k]< min){
                    min = tower[i][k];
                
                }
            }
        arr1[k] = min;
        }

        for(int j = 0;j<5;j++){
        for(int k = 0;k<4;k++){
            for(int i = 0;i<5;i++){
                if(tower[i+1][j]< tower[i][j]){
                    swap(tower[i+1][j],tower[i][j]);
            
            }
        
            }
        }
        arr2[j] = tower[0][j];
    }
    
}

int main(){


double x = function_1();
//double tower = function_2(x);
demo_1 tower;
tower = function_2(x);




    return 0;
}