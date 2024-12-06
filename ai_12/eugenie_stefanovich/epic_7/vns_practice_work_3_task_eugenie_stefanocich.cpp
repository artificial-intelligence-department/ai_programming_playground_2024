#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double  U , R , a , b , c ,d;
     
    cin >> U >> R;
    cin >> a >> b >> c >> d;

    cout << "I = " << U/R << endl;
    cout <<  "(a*b) - (c*d) = " << (a*b) - (c*d);
    return 0;
}