#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    int *array = new int[N];
    for (int i=0; i<N; i++){
        cin>>array[i];
    }
    sort(array, array+N);
    int m=0;
    while(1){
        if(N==1) {cout<<m; break;}
        if(array[1]==array[0]) {
            if(array[N-2]==array[N-1]){
                m=array[N-1]-array[0];
                cout<<m;
                break;
            }
            m=array[N-2]-array[0];
            cout<<m;
            break;
        }
        if(array[N-2]==array[N-1]){
            if(array[1]==array[0]){
                m=array[N-1]-array[0];
                cout<<m;
                break;
            }
            m=array[N-1]-array[1];
            cout<<m;
            break;}
            
        
        if(array[N-1]-array[0]>array[N-2]-array[0]&&array[N-2]-array[0]<=array[N-1]-array[1]){
            m=array[N-2]-array[0];
            cout<<m;
            break;
        }
        else if(array[N-1]-array[0]>array[N-1]-array[1]){
            m=array[N-1]-array[1];
            cout<<m;
            break;
        }}

    delete[]array;
    return 0;
}