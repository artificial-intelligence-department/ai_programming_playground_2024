#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double a1 = 100;
    double b1 = 0.001;
    double one, two, three, four, five, result; 

    one = pow((a1-b1), 4);
    two = pow(a1,4) - 4*pow(a1,3)*b1;
    three = 6*pow(a1, 2)*pow(b1,2);
    four = 4*a1*pow(b1,3);
    five = pow(b1,4);

    result = (one - two)/(three-four+five);

    float a2 = 100;
    float b2 = 0.001;
    float one2, two2, three2, four2, five2, result2; 

    one2 = pow((a2-b2), 4);
    two2 = pow(a2,4) - 4*pow(a2,3)*b2;
    three2 = 6*pow(a2, 2)*pow(b2,2);
    four2 = 4*a2*pow(b2,3);
    five2 = pow(b2,4);

    result2 = (one2 - two2)/(three2-four2+five2);

    cout << "Тип даних double: ";
    cout << result << endl;
    cout << "Тип даних float: ";
    cout << result2;

    return 0;
}