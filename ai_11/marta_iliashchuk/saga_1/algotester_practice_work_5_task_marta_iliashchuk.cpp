#include <iostream>
#include <cmath>
using namespace std;

//Торт для Петрика (191)

int main(){
    double n, r;
    cin>>n>>r;
    
    double result = sqrt(r*r/n);
    cout<<result;

    return 0;
}

