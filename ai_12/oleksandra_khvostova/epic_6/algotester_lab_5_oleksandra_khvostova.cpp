#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    vector<string> cave(N);
    for(int i=0; i<N; i++){
        cin>>cave[i];
    }
    for(int i=N-2; i>=0; i--){
        for(int j=0; j<M; j++){
            if(cave[i][j]=='S'){
                int ptr = i;
                for(int k=i+1; k<N; k++){
                    if(cave[k][j] == 'O') ptr = k;
                    else break;
                }
                swap(cave[i][j], cave[ptr][j]);
            }
        }
    }
    cout<<endl;
    for(string str: cave) cout<<str<<endl;
    return 0;
}