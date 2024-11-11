#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int x = n---m; // спочатку виконується операція n-- 
    bool y = m--<n; //спочатку виконується операція m--
    bool z = n++>m; // спочатку виконується операція n++
    cout << "n---m = " << x << endl;
    cout << "m--<n = " << y << endl;
    cout << "n++>m = " << z << endl;

    return 0;
}