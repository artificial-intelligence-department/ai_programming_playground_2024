#include <iostream>
#include <cmath>



int main(){


float a = 0.5, b = 2.9, x = 0.3; //Використовую float для зберігання невеликих змінних

double numerator_U = pow(a, 3) + exp(-x) * cos(b * x);  //Використовую double для зберігання великих обчислень
double denominator_U = b * x - exp(-x) * sin(b * x) + 1;
double U = numerator_U / denominator_U;


double F = exp(2*x)*log(a+x) - pow(b, 3*x)*log(fabs(x - b));

std::cout << "U = " <<  U << "\nF = " << F; //Виводжу результати підрахунків



    return 0;
}