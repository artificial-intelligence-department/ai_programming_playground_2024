#include <iostream>
#include <complex>

using namespace std;


void miltiplNormalNumbers (int a, int b) {
    int result = a * b;
    cout << "Результат: " << result << endl;
}


void miltiplNormalNumbers (int a, int b, int c) {
    int result = a * b * c;
    cout << "Результат: " << result << endl;
}

void miltiplNormalNumbers (int a, int b, int c, int d) {
    int result = a * b * c * d;
    cout << "Результат: " << result << endl;
}

void miltiplComplexNumbers (complex<int> a, complex<int> b) {
    
    auto result = a * b ;
    cout << "Результат: " << result << endl;
}

void miltiplComplexNumbers (complex<int> a, complex<int> b, complex<int> c , complex<int> d) {
    
    auto result = a * b * c * d;
    cout << "Результат: " << result << endl;
}
void miltiplComplexNumbers (complex<int> a, complex<int> b, complex<int> c ) {
    
    auto result = a * b * c ;
    cout << "Результат: " << result << endl;
}


int main(){

    miltiplNormalNumbers(2,6,4);
    miltiplNormalNumbers(1,7);
    miltiplNormalNumbers(4,3,5,4);
    miltiplComplexNumbers( complex<int> (0, 4), complex<int> (2, 3), complex<int> (7, 4), complex<int> (5, 9));
    miltiplComplexNumbers( complex<int> (6, 1), complex<int> (8, 2), complex<int> (7, 3));
    miltiplComplexNumbers( complex<int> (1, 2), complex<int> (3, 3));

    

    return 0;
}