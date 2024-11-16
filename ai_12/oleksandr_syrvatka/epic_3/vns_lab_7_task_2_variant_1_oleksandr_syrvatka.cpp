#include <iostream>
#include <complex>

using namespace std;

int add (int a, int b){
    return a+b;
}

complex <double> add (complex <double> a, complex <double> b){
    return a+b;
}


int main() {
    int a,b;
    cout << "Введіть два цілих числа: ";
    cin >> a >> b;
    cout << "Результат додавання заданих цілих чисел = " << add(a,b) <<"\n";

    complex <double> c, d;
    double real1, imaginable1, real2, imaginable2;
    cout << "Введіть два комлпексних числа: ";
    cin >> real1 >> imaginable1 >> real2 >> imaginable2;
    c = complex<double>(real1 , imaginable1);
    d = complex<double>(real2 , imaginable2);
    cout << "Результат додавання заданих комплексних чисел = " << add(c,d);

    return 0;
}