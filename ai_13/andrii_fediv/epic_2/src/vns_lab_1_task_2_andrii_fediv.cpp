#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    cout << "enter n: ";
    double d_n;
    cin >> d_n;
    cout << "enter m: ";
    double d_m;
    cin >> d_m;
    float f_n = static_cast<float>(d_n), f_m = static_cast<float>(d_m);

    cout << "\nFor float:\nn++ * m: " << (f_n++ * f_m) << "\nn++ < m: " << ((f_n++ < f_m) ? "true" : "false") << "\nm-- > m: " << ((f_m-- > f_m) ? "true" : "false");
    cout << "\nFor double:\nn++ * m: " << (d_n++ * d_m) << "\nn++ < m: " << ((d_n++ < d_m) ? "true" : "false") << "\nm-- > m: " << ((d_m-- > d_m) ? "true" : "false");

    return 0;
}