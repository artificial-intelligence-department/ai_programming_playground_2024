#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    int rest = 0;

    count += n / 500;
    rest = n % 500;

    count += rest / 200;
    rest = rest % 200;

    count += rest / 100;
    rest = rest % 100;

    count += rest / 50;
    rest = rest % 50;

    count += rest / 20;
    rest = rest % 20;

    count += rest / 10;
    rest = rest % 10;

    count += rest / 5;
    rest = rest % 5;

    count += rest / 2;
    rest = rest % 2;
    
    count += rest;

    cout << count;
}