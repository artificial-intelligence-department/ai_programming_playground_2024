#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std; 

int main(){
    double a = 0.1;
    int b = 1;
    int k = 10;
    double x;
    int n = 30;
    double e = 0.0001;

    double step = (b-a)/k;

    double func[k+1];
    double nres[k+1];
    double eres[k+1];

    for(int i=0; i<=k; i++){
        x = a + step*i;
        double sum1 = 0, sum2 = 0;
        double y = (1 + pow(x, a))/2 * atan(x) - x/2;
        func[i] = y;
        for(int j=0; j<n; j++){
            double temp = pow((-1), n+1) * (pow(x,2*n+1))/(4*pow(n,2) - 1);
            sum1 += temp;
        }
        nres[i] = sum1;
        
        int n_e = 1;
        double tempe = 1;
        while (tempe > e){
            tempe = pow((-1), n_e+1) * (pow(x,2*n_e+1))/(4*pow(n_e,2) - 1);
            sum2 += tempe;
            n_e++;
        }
        eres[i] = sum2;
    }

    cout << fixed << setprecision(6); 
    for (int i = 0; i <= k; i++) {
        cout << "x = " << a + step * i << ", SN = " << nres[i] 
             << ", SE = " << eres[i] << ", Y = " << func[i] << endl;
    }


    return 0;
}