#include <iostream>
#include <cmath>

 int main (){
    double x = 0.3;
    double a = 0.5;
    double b = 2.9;

    double a_to_x = pow (a, x);
    double b_to_minus_x = pow (b, -x );
    double sin_a_minus_b = sin (a - b);
    double sqrt_a_minus_b = sqrt (fabs(a -b ));

 double alpha  = ( a_to_x + b_to_minus_x * sin_a_minus_b )/ sqrt_a_minus_b ;
      
    double sqrt_a = sqrt(a);
    double cos_bxa = cos ((b * x) / a);

 double beta = ( a * exp (-sqrt_a) * cos_bxa);
  
     std::cout << " α = " << alpha << std::endl;
     std::cout << " β = " << beta << std::endl;

     return 0;
 } 