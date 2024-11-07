#include <iostream>
#include <math.h>
using namespace std;




int main() {

    float a_1,b_1, k_1, m_1, n_1,r_1;
    a_1 = 100;
    b_1 = 0.001;
    k_1 = pow((a_1-b_1),4);
    m_1 = pow(a_1,4)-4*pow(a_1,3)*b_1;
    n_1 = 6*pow(a_1,2)*pow(b_1,2)-4*a_1*pow(b_1,3)+pow(b_1,4);
    r_1 = (k_1-m_1)/n_1;
    cout << "Results"<<endl;
    cout << r_1 << endl;

    double a_2,b_2, k_2, m_2, n_2,r_2;
    a_2 = 100;
    b_2 = 0.001;
    k_2 = pow((a_2-b_2),4);
    m_2 = pow(a_2,4)-4*pow(a_2,3)*b_2;
    n_2 = 6*pow(a_2,2)*pow(b_2,2)-4*a_2*pow(b_2,3)+pow(b_2,4);
    r_2 = (k_2-m_2)/n_2;
    cout << r_2;
    
    return 0;
}