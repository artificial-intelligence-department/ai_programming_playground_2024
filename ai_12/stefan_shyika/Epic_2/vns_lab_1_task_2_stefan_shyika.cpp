#include<iostream>

using namespace std;

int main(){
    int n = 1;
    int m = 1;
    cout << ++n * ++m << endl;
    cout << (m++ < n) << endl;
    cout << (n++ > m) << endl;

}