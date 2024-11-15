#include <iostream>
#include <complex>

using namespace std;
int divisionintegers(int a, int b){
    if(b == 0){
        cout<<"division by 0 is not possible";
    }
    return a/b;
}

complex<double> division(complex<double> a, complex<double> b){
    if(b == complex<double>(0,0)){
        cout<<"division by 0 is not possible"<<endl;
        return complex<double>(0,0); 
    }
    return a/b;
}

int main(){
    int x = 10;
    int y = 2;
    cout<<"Result division by integers: " <<division(x,y)<<endl;

    complex<double> c1(4.0, 3.0); 
    complex<double> c2(2.0, 1.0); 
    complex<double> result = division(c1, c2);
    cout << "Result division complex numbers: " << result << endl;

    return 0;
}
