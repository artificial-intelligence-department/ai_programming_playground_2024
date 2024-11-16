#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,M,x;
    vector <int> n,m;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        n.push_back(x);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> x;
        m.push_back(x);
    }
    int c1 = 0;
    for(int n0:n){
        for(int m0:m){
            if(n0 == m0){
                c1 += 1;
            }
        }
    }
    cout << c1 << endl;
    cout << n.size() + m.size() - c1;
    return 0;
}