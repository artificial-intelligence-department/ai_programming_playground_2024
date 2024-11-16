#include <iostream>
using namespace std;

int main(){
    string given;
    cin >> given;
    int count=1;
    cout << given[0];
    for(int i=1; i < given.size()-1; i++){
        if((given[i]==given[i-1])){
            count++;
        } else {
            if(count>1){
                cout << count;
                count=1;
            }
            cout << given[i];
        }
    }
    if((given[given.size()-1] == given[given.size()-2])){
        cout << count+1;
    } else {
        if((given.size() > 1)){
            if(count>1){
                cout << count;
            }
            cout << given[given.size()-1];
        }
    }
    return 0;
}