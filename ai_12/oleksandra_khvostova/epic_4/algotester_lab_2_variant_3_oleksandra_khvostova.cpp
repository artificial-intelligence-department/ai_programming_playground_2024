#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int* array = new int[N];
    for(int i=0; i<N; i++){
        cin>>array[i];
    }
    int IndexL=0;
    int IndexR=N-1;
    int valL=0;
    int valR=0;
    for (IndexL, IndexR; valL=array[IndexL], valR=array[IndexR]; IndexL+=valL, IndexR-=valR){
        if(IndexL==IndexR){
            cout<<IndexL+1<<" "<<IndexR+1<<endl<<"Collision"; 
            break;
        }
        if(IndexL+1==IndexR){
            cout<<IndexL+1<<" "<<IndexR+1<<endl<<"Stopped"; 
            break;
        }
        if(IndexL>IndexR){
            cout<<IndexL+1<<" "<<IndexR+1<<endl<<"Miss"; 
            break;
        }
    }
    delete[]array;
    return 0;
}