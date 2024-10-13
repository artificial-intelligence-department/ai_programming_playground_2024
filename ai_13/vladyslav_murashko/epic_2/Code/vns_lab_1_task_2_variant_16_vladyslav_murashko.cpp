#include <iostream>

using namespace std;

int main()
{
    int n = 5, m = 4;

    cout << "\n++n * ++m = " << ++n * ++m << endl;
    cout << "m++ < n = "<< (m++ < n) << endl;
    cout << "n++ > m = "<< (n++ > m) << "\n\n";

    return 0;
}