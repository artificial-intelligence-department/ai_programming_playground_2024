#include <iostream>
using namespace std;

int main(){
int m = 9, n = 19;
int x = m-++n;
int y = ++m>--n;
int z = --n<++m;
cout << x << endl << y << endl << z << endl;

}