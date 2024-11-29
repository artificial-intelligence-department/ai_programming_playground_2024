#include <iostream> 
#include <cmath>

using namespace std;

int main () {
    int a = 10;
    int b = 11;
    int c = 17;
    double p, ha, hb, hc, temp1, temp2;

    p = (a + b + c)/2;

    temp1 = p*(p - a)*(p - b)*(p - c);
    temp2 = sqrt(temp1);

    ha = 2*temp2/(double)a;
    hb = 2*temp2/(double)b;
    hc = 2*temp2/(double)c;

    cout << "ha = " << ha << endl;
    cout << "hb = " << hb << endl;
    cout << "hc = " << hc << endl;

    return 0;
}