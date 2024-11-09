#include<iostream>
#include<vector>
using namespace std;

int main(){

    int N;
    cin >> N;

    if(N > 1e5 || N < 1){
        return 1;
    }

    vector<int> r(N);
    for (int i = 0; i < N; i++) {
        cin >> r[i];
        if(r[i] > 1e5 || r[i] < 0){
             return 1;
        }
    }

    int arr[3];

    for(int i = 0; i < 3; i++){
        cin >> arr[i];
        if(arr[i] > 1e5 || arr[i] < 0){
            return 1;
        }
    }

    vector<int> nR;
    for(int i = 0; i < N; i++){
        if(r[i] != arr[0] && r[i] != arr[1] && r[i] != arr[2]){
            nR.push_back(r[i]);
        }
    }
    
     if (nR.size() > 1) {
        vector<int> sum(nR.size() - 1);
        for (int i = 0; i < nR.size() - 1; i++) {
            sum[i] = nR[i] + nR[i + 1];
        }

        cout << sum.size() << endl;
        for (int s : sum) {
            cout << s << " ";
        }
    } else {
        cout << 0 << endl;
    }

    return 0;
}
