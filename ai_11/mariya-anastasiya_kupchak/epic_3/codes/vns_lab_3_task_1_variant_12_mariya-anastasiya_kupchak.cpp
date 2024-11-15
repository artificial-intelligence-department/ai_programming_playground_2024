#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std; 

int main()
{
    double a = 0.1;
    double b = 0.8;
    int k = 10;
    double x;
    int n = 35;
    double e = 0.0001;
    const double PI = 3.141592653589793238;

    double step = (b-a)/k;

    double func[11];  // масив для збереження точних значень функції
    double nres[11];  // сума ряду з встановленим n
    double eres[11];  // сума ряду з встановленою точністю

    for(int i=0; i<=k; i++)
    {
        x = a + step*i;

        double sum1 = 0, sum2 = 0;

        double y = -(1/2) * log(1 - (2 * x * cos(PI/3)) + pow(x, 2));  // обчислюємо точні значення функції
        func[i] = y;

        for(int j=0; j<n; j++)
        {
            double temp = (pow(x, n) * cos((n * PI) / 3)) / n;  // обчислюємо всі елементи ряду з заданим n
            sum1 += temp;
        }

        nres[i] = sum1;
        
        int n_e = 1;
        double tempe = 1;

        while (tempe > e)
        {
            tempe = (pow(x, n_e) * cos((n_e * PI) / 3)) / n_e;  // обчислюємо всі елементи ряду з заданою точністю
            sum2 += tempe;
            n_e++;
        }

        eres[i] = sum2;
    }

    cout << fixed << setprecision(5); 

    for (int i = 0; i <= k; i++) 
    {
        cout << "x = " << a + step * i << ", SN = " << nres[i]; 
        cout << ", SE = " << eres[i] << ", Y = " << func[i] << endl;
    }

    return 0;

}