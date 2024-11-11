#include <iostream>

using namespace std;

int main (){
    int n, m;
    cout << "Please, enter n and m : " ;
    cin >> n >> m ;

        //First, --m is calculated, then ++n, then --m - ++n
    int c1 = --m - ++n;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl; 
    cout << " --m - ++n = " << c1 << endl;   
        //First. m*n is calculated, then we compare it with previous ++n
    bool c2 = m*n < n++;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;
    cout << " m*n < n++ = " << c2 << endl;
        //We compare n++ with previous m--
    bool c3 = n-- > m++;
    cout << "n = " << n << endl;
    cout << "m = " << m << endl;
    cout << " n-- > m++ = " << c3 << endl;

    return 0;
}