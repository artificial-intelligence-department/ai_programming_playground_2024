#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string c;
    cin >> c;
    int v_count = 0, k_count = 0, K = 0, V = 0;
    for(char i : c){
        if(i == 'V'){
            v_count++;
        }
        else{
            k_count++;
        }
        if(v_count >= 11 && v_count - k_count >= 2){
            V++;
            v_count = 0;
            k_count = 0;
        }
        else if(k_count >= 11 && k_count - v_count >= 2){
            K++;
            v_count = 0;
            k_count = 0;
        }
    }
    cout << K << ':'<< V;
    if(v_count !=0 || k_count != 0){
        cout << endl << k_count << ':' << v_count;
    }
    return 0;

}
