#include <iostream>
#include <math.h>

int main() {
    float af = 100;
    float bf = 0.001;
    float denominatorf, numeratorf;
    numeratorf = pow(af + bf, 4) - (pow(af, 4) + 4 * pow(af, 3) * bf);
    denominatorf = 6 * pow(af, 2) * pow(bf, 2) + 4 * af * pow(bf, 3) + pow(bf, 4);
    float resultf = numeratorf/denominatorf;
    std::cout << resultf << std::endl;

    double ad = 100;
    double bd = 0.001;
    double denominatord, numeratord;
    numeratord = pow(ad + bd, 4) - (pow(ad, 4) + 4 * pow(ad, 3) * bd);
    denominatord = 6 * pow(ad, 2) * pow(bd, 2) + 4 * ad * pow(bd, 3) + pow(bd, 4);
    double resultd = numeratord/denominatord;
    std::cout << numeratord/denominatord << std::endl;
};
