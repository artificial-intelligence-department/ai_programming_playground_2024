#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void checkAscending(int * f_column, int N){
    bool result = true;
    for(int i = 0 ; i < sqrt(N) - 1; i++){
        if(f_column[i+1] < f_column[i]){
            result = false;
        }
    }
    if(result){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

}

int main(){
    string l;
    cout << endl;
    cin >> l;
    int N = l.size();
    int f_column[100];
    int j = 0;
    for(int i = 0; i < N; i += sqrt(N)){
        f_column[j++] = l[i];
    }
    checkAscending(f_column, N);
    
    return 0;
}
