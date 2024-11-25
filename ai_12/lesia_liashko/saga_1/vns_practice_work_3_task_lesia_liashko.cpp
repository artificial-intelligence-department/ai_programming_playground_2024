#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main (){
    double time, l, v, min;
    int sec;
    
    cout << "Введіть відствнь (метри):" << endl;
    cin >> l;
    cout << "Введіть час (хв - пробіл - сек):" << endl;
    cin >> time >> sec;
    
    min= time * 60;
    v=(l/(min + sec))*3.6;

    cout << fixed << setprecision(2);
    cout << v << "км/год" << endl;

    double r, u, i;
    
    cout << "Введіть значення напруги:" << endl;
    cin >> u;
    cout << "Введіть значення сили струму" << endl;
    cin >> i ;
if (i==0){
    return -1;
}
 else {
     r = u/i;
    cout << r << " Ом" ;

 }
   return 0;
}
