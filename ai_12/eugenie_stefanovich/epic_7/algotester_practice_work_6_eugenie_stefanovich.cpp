#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long prev = -1 , a;
    for (int i = 0; i < 5; i++){
        cin >> a;
        if(a <= 0){
            cout << "ERROR";
            exit(0);
        } else if (a > prev && prev != -1){
            cout << "LOSS";
            exit(0);
        } 
        prev = a;
    }
    cout << "WIN";


    return 0;
}