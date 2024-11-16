#include <iostream>
#include <cmath>

using namespace std;


int main(){
    float m;
    float n;
    float result1;
    bool result2;
    bool result3;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    result1 = (++n) * (++m);
    result2 = (m++) < n;
    result3 = (n++) > m;
    
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;

    return 0;
}
