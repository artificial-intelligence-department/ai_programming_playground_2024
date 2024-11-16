#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cout << "Введіть n" << endl;
    cin >> n;
    cout << "Введіть m" << endl;
    cin >> m;

    int op_1 = (++n)*(++m);
    cout <<"++n*++m = " << op_1 << endl;
    
    int op_2 = m++ < n;
    cout <<"m++ < n = " << op_2 << endl;

    int op_3 = n++ > m;
    cout <<"n++ > m = " << op_3 << endl;

    return 0;
} 