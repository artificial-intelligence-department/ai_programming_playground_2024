#include <iostream>
#include <cmath>
#include <vector>

double triangle(double a, double b, double c){
double p = (a + b + c)/2;
double square = sqrt(p * (p-a) * (p-b) * (p-c)); 
    return square;
}


double perymetr(const std::vector<double> &sides){
double P = 0;
for(auto temp: sides)
    P += temp;
    return P;
}


int main(){

std::vector<double> sides1  {3, 5, 19.2};
std::vector<double> sides2 {18.2, 12.3, 6.7, 3, 10, 16};
std::vector<double> sides3 {8.2, 5.3, 4.3, 3, 9, 10, 12.23, 5};




std::cout << "perimeter of first polygon: "<< perymetr(sides1) << std::endl;
std::cout << "perimeter of second polygon: "<< perymetr(sides2) << std::endl;
std::cout << "perimeter of third polygon: "<< perymetr(sides3) << std::endl;



    return 0;
}