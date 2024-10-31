#include <iostream>
#include <cmath>

using namespace std;


int main(){
    float af = 100;
    float bf = 0.001;
    float resultf; 
    float numeratorf;
    float denominatorf;

    numeratorf = pow(af+bf, 4) - (pow(af, 4) + 4*pow(af,3) * bf);
    denominatorf = 6*pow(af, 2)*pow(bf, 2) + 4*af*pow(bf, 3) + pow(bf, 4);
    resultf = numeratorf / denominatorf;
    cout << "Float result: " << endl;
    cout << numeratorf << endl;
    cout << denominatorf << endl;
    cout << resultf << endl;

    double ad = 100;
    double bd = 0.001;
    double resultd; 
    double numeratord;
    double denominatord;

    numeratord = pow(ad+bd, 4) - (pow(ad, 4) + 4*pow(ad,3) * bd);
    denominatord = 6*pow(ad, 2)*pow(bd, 2) + 4*ad*pow(bd, 3) + pow(bd, 4);
    resultd = numeratord / denominatord;
    cout << "Double result: " << endl;
    cout << numeratord << endl;
    cout << denominatord << endl;
    cout << resultd << endl;

    return 0;
}
