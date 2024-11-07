#include <iostream>
#include <cmath>
using namespace std;

int main (){
 double al, bl, one, two, three, four, five;
 al = 1000;
    bl = 0.0001;
     one = pow((al + bl), 2);
    two = pow(al, 2);
    three = one + (2 * al * bl);
    four = pow(bl, 2);
    five = (one - three /  four);
 cout << "a=1000, b=0.0001" << endl;
   cout << "Double:" << five << endl;
    
    float af, bf, step1, step2, step3, step4, step5;
    af = 1000;
    bf = 0.0001;
    step1 = pow((af + bf), 2);
    step2 = pow(af, 2);
    step3 = step1 + (2 * af * bf);
    step4 = pow(bf, 2);
    step5 = (step1 - step3 /  step4);
    cout << "Float:" << step5 << endl;
}
