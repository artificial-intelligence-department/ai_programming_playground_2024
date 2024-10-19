#include <iostream>
#include <cmath>

//float    //18 варіант
int main(){

float aF = 1000;
float bF = 0.0001;
float numeratorF, enumeratorF, resultF; //numerator - чисельник
numeratorF = pow(aF-bF,3) - pow(aF,3);
enumeratorF = pow(bF,3) - 3*aF*pow(bF,2) - 3*pow(aF,2)*bF;
resultF = numeratorF / enumeratorF;
std::cout << "Результат при float = " << resultF <<std::endl;

double aD = 1000;
double bD = 0.0001;
double numeratorD, enumeratorD, resultD; //numerator - чисельник
numeratorD = pow(aF-bF,3) - pow(aF,3);
enumeratorD = pow(bF,3) - 3*aF*pow(bF,2) - 3*pow(aF,2)*bF;
resultD = numeratorD / enumeratorD;
std::cout << "Результат при double = " << resultD <<std::endl;

return 0;

}