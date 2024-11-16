#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, x;
    vector <int> arr;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        arr.push_back(x);
    }
    int pos1 = 0, pos2 = N-1;
    while(1){
        if(pos1 == pos2){
            cout << pos1+1 << " " << pos2+1 << endl;
            cout << "Collision";
            break;
        }
        else if(pos1 > pos2){
            cout << pos1+1 << " " << pos2+1 << endl;
            cout << "Miss";
            break;
        }
        else if(pos1 + 1 == pos2){
            cout << pos1+1 << " " << pos2+1 << endl;
            cout << "Stopped";
            break;
        }
        pos1 += arr[pos1];
        pos2 -= arr[pos2];
    }

    return 0;
}