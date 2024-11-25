#include <iostream>
#include <complex>

using namespace std;

double addition_real_numbers(double r1, double r2){
    return r1 + r2;
}

double addition_real_numbers(double r1, double r2, double r3){
    return r1 + r2 + r3;
}

double addition_real_numbers(double r1, double r2, double r3, double r4){
    return r1 + r2 + r3 + r4;
}

complex<int> addition_complex_numbers(complex<int> c1, complex<int> c2){
    return c1 + c2;
}

complex<int> addition_complex_numbers(complex<int> c1, complex<int> c2, complex<int> c3){
    return c1 + c2 + c3;
}

complex<int> addition_complex_numbers(complex<int> c1, complex<int> c2, complex<int> c3, complex<int> c4){
    return c1 + c2 + c3 + c4;
}
int main(){
    
    //add real numbers
    
    cout << addition_real_numbers(8, 2.3) << endl;
    cout << addition_real_numbers(7, 2.3, 4.3) << endl;
    cout << addition_real_numbers(3, 2.5, 12.7, 3.8) << endl;
    
    //add complex numbers
    
    cout << addition_complex_numbers(3, 5) << endl;
    cout << addition_complex_numbers((3, 7), (6, 2), (5, 4)) << endl;
    cout << addition_complex_numbers((8, 6), (8, 10), (9, 1), (10, 3)) << endl;
    return 0;
}