#include <iostream>
#include <cmath>

template <typename T>
T operations(T  a,T b){
   T t1 = a - b;
   T t2 = pow(t1, 4);
   T t3 = pow(a, 4);
   T t4 = 4 * pow(a, 3) * b;
   T t5 = 6 * pow(a, 2) * pow(b , 2);
   T t6 = 4 * a * pow(b , 3);
   T t7 = pow(b, 4);
   T c = t5 - t6 + t7;
   T c1 = t2 - t3 + t4;
   T t12 = c1 / c;
    return t12;
}

using namespace std;
int main(){
    float f_a = 100.0f, f_b = 0.001f;
    double d_a = 100.0 , d_b = 0.001;
    float float_result = operations(f_a, f_b);
    double double_result = operations(d_a, d_b);

    cout << "float result: " << float_result << "\ndouble result: " << double_result;
    //різниця виникає через точність типу залежності від к-сті цифр після коми
    return 0;
}