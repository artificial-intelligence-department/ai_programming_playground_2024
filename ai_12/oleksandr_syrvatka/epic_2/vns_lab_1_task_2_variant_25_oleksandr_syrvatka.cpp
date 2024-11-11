#include <iostream>

using namespace std;

int main(){
    
    int n, m;
    cout << "Введіть змінні n та m: ";
    cin >> n >> m;
    cout << (--m-++n)<<"\n";
    cout << (m*n<n++)<<"\n";
    cout << (n-->m++)<<"\n";

    return 0;
}