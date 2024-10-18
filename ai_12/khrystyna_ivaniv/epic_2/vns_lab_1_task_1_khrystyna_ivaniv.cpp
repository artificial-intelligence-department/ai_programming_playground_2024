#include <iostream>
#include <math.h>

int main (){
    float af = 100, bf = 0.001;

    float numeratorF = pow(af+bf, 4) - (pow(af, 4) + 4*pow(af, 3)*bf);
    float denominatorF = 6*pow(af, 2)*pow(bf, 2) + 4*af*pow(bf, 3) + pow(bf, 4);
    float resultF = numeratorF/denominatorF;

    std::cout << resultF <<std::endl;

    double ad =100, bd =0.001;

    double numeratorD = pow(ad+bd, 4) - (pow(ad, 4) + 4*pow(ad, 3)*bd);
    double denominatorD = 6*pow(ad, 2)*pow(bd, 2) + 4*ad*pow(bd, 3) + pow(bd, 4);
    double resultD = numeratorD/denominatorD;

    std::cout << resultD;

    return 0;
}