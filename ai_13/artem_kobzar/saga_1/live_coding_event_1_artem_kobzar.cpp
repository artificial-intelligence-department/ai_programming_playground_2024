#include <iostream>
#include<iostream>

using namespace std;

float function_1(){
    float a,b;
    int c,d,e;
    double f;
    cin>>a>>b>>c>>d>>e>>f;
    float minSum=0.0;
    float maxSum=0.0;
    double arr[5]={a,b,c,d,e,f};
    sort(arr,arr+6);
    cout<<"Min elements: "
    for (int i=0;i<3;i++){
        cout<<arr[i]
    }
    cout<<"Max elements:"
    for(int i=3; i<6;i++) {
        cout<<arr[i]
    }
    cout<<endl;
    minSum = arr[0]+arr[1]+arr[2];
    maxSum = arr[3]+arr[4]+arr[5];


    
    return x;
    float** function_2(float&x) {
        float **arr =new float *[5];
        for (int i=0;i<5;i++){
            arr[i]=new float[5];
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++) {
                arr[i][j]=x;
            } 
        }
        for(int i=0; i<5;i++){
            for (int j=0;l<5;j++) {
                arr[i][j]=newX;
            }
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++) {
                cout<<arr[i][j];
            } 
            cout<<endl;
        }
        return arr;
    }
}
float* function_3(float **tower){
    float* arr_1= new float[5];
    for(int i=0;i<5;i++){
        float min=tower[i][0];
        for(int j=0;j<5;j++) {
            if(min>tower[i][j]) {
                min=tower[i][j];
            }
            arr_1[i]=min;
        } 
        cout<<endl;
    }
    for(int i=0;i<5;i++){
        float minimum =min(tower[i][j], tower[i][j+1]);
    }
    arr_2[i]=minimum;
}
for(int i=0;i<5;i++) {
    bool isEqual =true;
    if(arr_1[i]=arr_2[i]){
        isNotEqual=true;
        break;
    }
}
if(!isEqual) {
    cout<<"Isn't Equal"<<endl;
} else
{
    cout<"Equal";
    return arr_1;
}


int main() {
    float**matrix=function

}