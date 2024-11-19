#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long prev = -1;
    for (int i = 0; i < 5; i++)
    {
        long long a;
        cin >> a;
        if(a <= 0){
            cout << "ERROR";
            return 0;
        } else if (a > prev && prev != -1){
            cout << "LOSS";
            return 0;
        } 
        prev = a;
    }
    cout << "WIN";


    return 0;
}