#include <iostream>
using namespace std;

int main(){

    int N ,k, v , perv, perk;
    cin >> N;
    k = 0;
    v = 0;
    perk = 0;
    perv = 0;
    char per;
    for(int i = 0; i < N;i++){
        cin >> per;
        if(per == 'K'){
            k++;
            if(k >= v+2 && k >= 11){
                perk++;
                 k = 0;
                 v = 0;
            }
        }


        if(per =='V'){
            v++;
            if(v >= k+2&& v >= 11){
                perv++;
                k = 0;
                v = 0;
            }

        }

    }
    cout << perk << ":" << perv << endl;
    if(k != 0|| v != 0)
        cout << k << ":" << v << endl;


    return 0;
}