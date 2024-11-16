#include <iostream>

using namespace std;

int main(){
int n, m;
cin >> n,m;


int op_1 = m - (++n);
cout << op_1 << endl;


bool op_2 = (++m) > (--n);
cout << op_2 << endl;

bool op_3 = (--n) < (++m);
cout << op_3 << endl;
}