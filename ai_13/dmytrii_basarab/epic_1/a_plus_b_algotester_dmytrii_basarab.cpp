#include <iostream>

using namespace std;

int main()
{
double a;
double b;
double sum;


cin >> a;
cin >> b;

if (a >= 0 && a <= 100 && b >= 0 && b <= 100){
double sum = a+b;
cout << sum;
}
else {
    cout << "Wrong number" << endl;
}
    return 0;
}
