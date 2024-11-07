//teeth
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, K, x;
    cin >> N >> K;
    vector<int> A;
    for(int i = 0; i < N; i++){
        cin >> x;
        A.push_back(x);
    }
    int c1 = 0, c2 = 0;
    for (int i : A){
        if(i >= K){
            c1 += 1;
        }
        else{
            if (c1 != 0 && c2 < c1){
                c2 = c1;
            }
            c1 = 0;
        }
    }
    if(c1 > c2){
        cout << c1;
    }
    else{
        cout << c2;
    }
    return 0;
}