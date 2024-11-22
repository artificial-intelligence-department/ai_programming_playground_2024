#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
    int N, n, a, b, c;
    vector <int> r;
   
    cin>>N;
   
    for (int num = 0; num<N; num++){
        cin>>n;
        r.push_back(n);
     }
    
    cin>>a>>b>>c;
    r.erase(remove_if(r.begin(), r.end(), [a, b, c](int x) {
        return x == a || x == b || x == c;
}), r.end());

    cout<<r.size() - 1<<endl;
    for(int i = 0; i <r.size()-1; i++){
        cout<<r[i] + r[i+1]<<" ";
    } 
    return 0;
}