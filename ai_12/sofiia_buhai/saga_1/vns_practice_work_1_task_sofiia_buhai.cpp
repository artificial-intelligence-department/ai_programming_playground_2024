//Розробити лінійний алгоритм для розв’язання задачі.
#include <iostream>
#include <cmath>

int main(){
    const double x = 0.25, y= 0.79, z = 0.81;
    double  P, P_act1, P_act2, P_act3, P_act4;
    double  Q, Q_act1;
    P_act1 = 1+pow(x,2)*pow(y,3);
    P_act2 = 2*pow(x,3)/P_act1;
    P_act3 = 1+pow(sin(x+1),2);
    P_act4 = 2+fabs(x-P_act2);
    P = P_act3/P_act4;
    std::cout << P << "\n";
    Q_act1 = atan(1/z);
    Q = pow(cos(Q_act1), 2);  
    std::cout << Q << "\n";
    return 0;
}