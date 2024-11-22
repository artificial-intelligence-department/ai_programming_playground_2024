#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N , wid , m , k;
    cin >> N;
    if(N > 2){
        vector<int> dlin;
        for(int i = 0; i < N; i++){
            cin >> wid;
            dlin.push_back(wid);
            }
            
        sort(dlin.begin(), dlin.end());

        m = dlin[N-2] - dlin[0];
        k = dlin[N-1] - dlin[1];

        if(m >k)
            cout << k;
        else    
            cout <<m;
    }

    else if(N==2){
        cin >> wid; 
        cin >> wid;
        cout << 0;
    }
    else{
        cin >> wid;
        cout << 0;
    }


    return 0;
}