#include <iostream>
using namespace std;

// Lab 2v3
int main()
{
    unsigned short N;
    cin >> N;
    unsigned short arr[N];
    for (auto &el : arr)
    {
        cin >> el;
    }
    short i = 1, j = N;
    while(true){
        if(i==j){
            cout << i << " " << j << endl << "Collision";
            return 0;
        }
        if(i+1==j){
            cout << i << " " << j << endl << "Stopped";
            return 0;
        }
        if(i>j){
            cout << i << " " << j << endl << "Miss";
            return 0;
        }
        i += arr[i-1];
        j -= arr[j-1];
    }
}