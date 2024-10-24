#include <iostream>
#include <cmath>
using namespace std;

int main (){
    float a = 1000;
    float b = 0.0001;

    float firstAct = pow((a - b),2) - (pow(a, 2) - 2*a*b);
    float secondAct = pow(b , 2) ;
    float thirdAct = firstAct / secondAct;
    cout << "Result: " << thirdAct << endl;

    double a1 = 1000;
    double b1 = 0.0001;

    double first_act = pow((a1 - b1),2) - (pow(a1, 2) - 2*a1*b1);
    double second_act = pow(b1 , 2) ;
    double third_act = first_act / second_act;
    cout << "Result: " << third_act << endl;
    return 0;
}
