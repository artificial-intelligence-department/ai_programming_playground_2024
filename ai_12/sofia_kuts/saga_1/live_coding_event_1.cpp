#include <iostream>
#include <cmath>
#include <limits>
#include <list>
#include <string>
#include <ctime>
#include <cstdlib>
 const int  variant = 42;
 struct Student {
    std::string firstName;
    std::string lastName;
 }

 double function_1 ();
  double a, b, f;
  int c, d, e;

  std::cout << " Введіть два дійсних числа (a,b): ";
  std::cin >> a >> b;
  std::cout << " Введіть три цілих числа (c, d, e): ";
  std::cin >> c >> d >> e;
  std::cout << " Введіть дійсне число з подвійною точністю (f): ";
  std::cin >> f ;

  double value [] = { a, b, f,  static_cast< double>(c), static_cast< double>(d), static_cast< double>(e) };

   double max_1 = std:: numeric_limits <double> :: lowest (), max_2 = max_1, max_3 = max_1;
   double min_1 = std:: numeric_limits <double> :: max (), min_2= min_1, min_3 = min_1;

   for ( double value : values ){
     if ( value > max_1 ){
        max_3 = max_2;
        max_2 = max_1;
        max_1 = value;
       } else if ( value > max_2){
        max_3 = max_2;
        max_2 = value;
       } else if ( value > max_3 ){
        max_3 = value;
       } 
    if ( value < min_1){
        min_3 = min_2;
        min_2 = min_1;
        min_1 = value;
    }
   }
    double sum_max = max_1 + max_2 + max_3;
    double sum_min = min_1 + min_2 + min_3;
    double result ;
    if (sum_max > sum_min * 2){
        result = sum_max * sum_min;
    } else if ( sum_max > sum_min * 3){
        result = sum_max\sum_min;
    } else if ( sum_max > sum_min * 4){
        result = sum_max + sum_min;
    }
    result \=variant ;
    std::cout << " Результати : " <<  result << std::endl;
    
    return result;
    // function_2
    double** function_2 (double x){
        double** matrix = new double*[5];
        for (int i = 0 ; i < 5 ; j++){
            matrix[i][j] = ( x + variant + j - i ) * (rand() % 100 +1 );

        }
    }
     std::cout << " Матриця:" << std::endl;
     for (int i = 0; i < 5; j++){
        for (int j = 0 ; j < 5 ; j++){
            std::cout << matrix[i][j] << " \t ";
        }
        std::cout << std::endl;
     }
     return matrix
     
int main (){
    double x = function_1();
    return 0;
}
