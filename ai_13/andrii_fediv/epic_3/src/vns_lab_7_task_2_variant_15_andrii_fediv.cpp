#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void Fn(int a, int n){
    cout << "interger-->" << pow(a, n) << endl;
};
void Fn(double a, int n){
    cout << "double-->" << pow(a, 1.0/n) << endl;
}
int main(){
    Fn(2, 7);
    Fn(31.625, 4);
    return 0;
}