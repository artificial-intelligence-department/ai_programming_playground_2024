#include <iostream>
#include <complex>

using namespace std;

//віднімання цілих чисел
int integer_numbers_subtraction(int z1, int z2){
    return z1 - z2;
}
int integer_numbers_subtraction(int z1, int z2, int z3){
    return z1 - z2 - z3;
}
int integer_numbers_subtraction(int z1, int z2, int z3, int z4){
    return z1 - z2 - z3 - z4;
}

//віднімання комплексних чисел
complex<int> complex_numbers_subtraction(complex<int> c1, complex<int> c2){
    return c1 - c2;
}
complex<int> complex_numbers_subtraction(complex<int> c1, complex<int> c2, complex<int> c3){
    return c1 - c2 - c3;
}
complex<int> complex_numbers_subtraction(complex<int> c1, complex<int> c2, complex<int> c3, complex<int> c4){
    return c1 - c2 - c3 - c4;
}

int main(){
    
    cout << "Integer numbers: " << endl;
    cout << "2 arguments: " << integer_numbers_subtraction(4, -3) << endl;
    cout << "3 arguments: " << integer_numbers_subtraction(2, 6, 3) << endl;
    cout << "4 arguments: " << integer_numbers_subtraction(8, 7, -4, 2) << endl;
    
    cout << "\nComplex numbers: " << endl;
    cout << "2 arguments: " << complex_numbers_subtraction(complex<int>(7, 2), complex<int>(0, 4)) << endl;
    cout << "3 arguments: " << complex_numbers_subtraction(complex<int>(-8, 9), complex<int>(2, 2), complex<int>(7, 0)) << endl;
    cout << "4 arguments: " << complex_numbers_subtraction(complex<int>(5, 4), complex<int>(3, 2), complex<int>(11, 7), complex<int>(-4, 3)) << endl;
    return 0;
}