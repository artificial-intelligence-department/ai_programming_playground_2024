#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a = 0;
    cout << "Введіть довжину ребра (см) і натисніть клавішу <Enter> ";
    cin >> a;
    
    double result = pow(a, 3);
    cout << fixed << setprecision(2);
    cout << "Об'єм куба: " << result << " куб.см.";

    return 0;
}