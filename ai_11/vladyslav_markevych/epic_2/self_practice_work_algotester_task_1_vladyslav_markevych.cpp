#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long a, mcookies = 0;
    cin>>a;

    vector<int> vec(a);
    for (int i=0; i < a; i++){
        cin>>vec[i];
        mcookies += vec[i] - 1;
    }

    cout<<mcookies<<endl;
    return 0;
}