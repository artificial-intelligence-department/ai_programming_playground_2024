#include <iostream>

using namespace std;

int main()
{
    float n1, m1, a1;
    double n2, m2, a2;
    bool b1, b2;
    
    cout << "Enter value for n (in float): ";
    cin >> n1;
    cout << "Enter value for m (in float): ";
    cin >> m1;

    cout << "Enter value for n (in double): ";
    cin >> n2;
    cout << "Enter value for m (in double): ";
    cin >> m2;

    a1 = n1-- - m1;
    a2 = n2-- - m2;


    cout << "Task2.1 output (from float values): "  << a1 << endl;
    cout << "Task2.1 output (from double values): "  << a2 << endl;

    b1 = m1-- < n1;
    b2 = m2-- < n2;

    cout << "Task2.2 output (from float values): "  << b1 << endl;
    cout << "Task2.2 output (from double values): "  << b2 << endl;
    
    return 0;

}