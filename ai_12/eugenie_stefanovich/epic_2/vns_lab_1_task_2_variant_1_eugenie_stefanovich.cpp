#include <iostream>

using namespace std;

int main()
{
    int m = 10, n = 10;
    int result = 0;

    result = n---m ;

    cout << "1)   n---m  " << endl;

    cout << result << endl; 

    m = 10;
    n = 10;
    cout << "2)m--<n" << endl;
    result = m--<n;
    cout << result << endl; 
    m = 10;
    n = 10;

    result =  n++>m;

    cout << "3) n++>m" << endl;

    cout << result << endl; 

    return 0;
}