#include <iostream>

using namespace std;

bool gameResult (long long int x, long long int y);

int main()
{
    long long int a, b, c, d, e;

    cin >> a;
    if(!(gameResult(a, a))){
        return 0; 
    }
    
    cin >> b;
    if(!(gameResult(a, b))){
        return 0; 
    }
    
    cin >> c;
    if(!(gameResult(b, c))){
        return 0; 
    }
    
    cin >> d;
    if(!(gameResult(c, d))){
        return 0; 
    }
    
    cin >> e;
        if(!(gameResult(d, e))){
        return 0; 
    }
    
    cout << "WIN";

    return 0;
}

bool gameResult (long long int x, long long int y){
    if (y <= 0 && y >= -10e11 && y <= 10e11){
        cout << "ERROR";
        return 0;
    }else if(x < y){
        cout << "LOSS";
        return 0;
    };

    return 1;
}