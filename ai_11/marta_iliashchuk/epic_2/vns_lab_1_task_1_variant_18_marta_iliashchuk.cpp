#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int main()
{
    float a_f = 1000;
    float b_f = 0.0001;
    double a_d = 1000;
    double b_d = 0.0001;
    string p = "((1000 - 0.0001)^3 - 1000^3)/( 0.0001^3 - 1000 * 0.0001^2 - 3 * 0.0001 * 1000^2)";
    float p_f1 = (a_f - b_f);
    double p_d1 = (a_d - b_d);

    float p_f2 = pow(a_f, 3);
    double p_d2 = pow(a_d, 3);

    float p_f3 = pow(b_f, 3);
    double p_d3 = pow(b_d, 3);

    float p_f4 = pow(b_f, 2);
    double p_d4 = pow(b_d, 2);

    float p_f5 = pow(a_f, 2);
    double p_d5 = pow(a_d, 2);

    float p_f6 = pow(p_f1, 3) - p_f2;
    double p_d6 = pow(p_d1, 3) - p_d2;

    float p_f7 = p_f3 - a_f*p_f4 - 3*b_f*p_f5;
    double p_d7 = p_d3 - a_d*p_d4 - 3*b_d*p_d5;
    
    float p_f8 = (pow((a_f - b_f), 3) - pow(a_f, 3))/(pow(b_f, 3) - a_f*pow(b_f, 2) - 3*b_f*pow(a_f, 2));
    double p_d8 = (pow((a_d - b_d), 3) - pow(a_d, 3))/(pow(b_d, 3) - a_d*pow(b_d, 2) - 3*b_d*pow(a_d, 2));

    cout<<p<<" = (" <<p_f1<<" - "<<p_f2<<")/("<<p_f3<<" - "<<a_f<<" * "<<p_f4<<"-"<< 3*b_f<<" * "<<p_f5<<") = "<<p_f6<<"/"<<p_f7<<" = "<<p_f8<<endl;
    
    cout<<p<<" = (" <<p_d1<<" - "<<p_d2<<")/("<<p_d3<<" - "<<a_d<<" * "<<p_d4<<"-"<< 3*b_d<<" * "<<p_d5<<") = "<<p_d6<<"/"<<p_d7<<" = "<<p_d8<<endl;

    return 0;
}