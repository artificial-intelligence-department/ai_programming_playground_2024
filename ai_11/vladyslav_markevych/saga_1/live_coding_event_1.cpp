#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

const int Variant = 17;

double function_1(){
    float a, b;
    int c,d,e;
    double f;
    cin>>a>>b;
    cin>>c>>d>>e;
    cin>>f;

    int n = 6;

    double arr[n] = {static_cast<double>(a),static_cast<double>(b),static_cast<double> (c), static_cast<double>(d), static_cast<double> (e), f};
    sort(arr, arr + n);

    double max = arr[3]+arr[5]+arr[4];
    double min = arr[0]+arr[1]+arr[2];

    double result; 

    if(max > min*2){
         result = max*min;
    }else if(max>min*3){
         result = max/min;
    }else if(max>min*4){
         result = max+min;
    }else{
        cout<<"Error"<<endl;
    }

    double final_result = result/Variant;
    return final_result;
}

void function_2(double& x, double matrix[5][5]){
for(int i = 0 ; i < 5; i++){
    for(int j = 0; j<5;j++){
        matrix[i][j] = x;
    }
}
srand(static_cast<unsigned int>(time(0)));
for(int a = 0; a < 5; a++){
    int value = rand() % 101;
    for(int b = 0; b<5;b++){
        matrix[a][b] = (matrix[a][b]+Variant+a-b)*value;
    }
}
cout<<"Нова матриця:"<<endl;

for(int c = 0; c<5;c++){
    for(int l = 0;l<5; l++){
        cout<<matrix[c][l]<<" ";
    }
    cout<<endl;
}

} 

int main(){
    double x = function_1();
    cout<<function_1();
    double matrix[5][5];
    function_2(x, matrix);

    return 0;
}

