#include <iostream>
using namespace std;

int main(){
    int m = 0, n = 0;

    cin >> m;
    cin >> n;

    //1)++n*++m
    int result1 = ++n * ++m;
    cout << "++n * ++m = " << result1 << endl;

    //2)m++<n
    bool result2 = m++ <n;
    cout << "m++ < n = " << result2 << endl;

    //3)n++>m
    bool result3 = n++ >m;
    cout <<"n++ > m  = " << result3 << endl;
    return 0;
}