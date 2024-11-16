#include <iostream>
using namespace std;
int main() 
{
    int n, m;
    cin>>n;
    cin>>m;
    
    cout<<"1)"<<n++*m<<endl; // n множиться на m, а потім  n збільшується на 1
    // у випадку (n++*m)*n  n(1) множиться на m, а потім набуває значення n + 1, тобто n(2) = n + 1
    cout<<"2)"<< (n++<m)<<endl; // n порівнюється з m, а потім n збільшується на 1
    cout<<"3)"<<( m-- > m);// порівнюємо m(1) з m(2), яке тепер m-1
    
    return 0;
}