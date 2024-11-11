#include "iostream"
#include "string"
using namespace std;

int main(){
    long long int h1, h2, h3, h4, d1, d2, d3, d4, h_max, h_min;
    cin >> h1 >> h2 >> h3 >> h4;
    cin >> d1 >> d2 >> d3 >> d4;

    long long int table[4] = {h1, h2, h3, h4};
    long long int d[4] = {d1, d2, d3, d4};
    h_max = h1;
    h_min = h1;
    bool nott = false;



    for(int k = 0; k < 4; k++){
        if (d[k] > table[k]){  
            cout << "ERROR";
            return 0;
        }

        table[k] -= d[k];
        h_max = table[0];
        h_min = table[0];
        for(int i = 0; i<4; i++){
            if (table[i] > h_max){
                h_max = table[i];
            }
            if (table[i] < h_min){
                h_min = table[i];
            }
        }
        if(h_max >= h_min*2 || h_min == 0){
            nott = true; 
        }
    }
    if (nott == true){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    
    return 0;
}
