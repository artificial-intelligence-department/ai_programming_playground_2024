#include <iostream>
using namespace std;
int main(){
    double U, R, I;
    cout << "Введіть значення напруги: ";
    cin >> U;
    cout << "Введіть значення сили струму: ";
    cin >> I;
    R = U/I;
    cout << "Опір = " << R << endl;
}