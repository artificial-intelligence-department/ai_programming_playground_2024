#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int supermanWins = 0;
    int batmanWins = 0;

    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;

        int nim_sum = a ^ b ^ c;

        if(nim_sum != 0){
            supermanWins++;
        }else{
            batmanWins++;
        }
    }
    cout << supermanWins << "-" << batmanWins;


    return 0;
}