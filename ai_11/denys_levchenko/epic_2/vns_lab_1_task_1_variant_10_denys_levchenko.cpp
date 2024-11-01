#include <iostream>
#include <math.h>

using namespace std;
int main(){
    int float_or_double;
    cout << "Виберіть флоат чи дабл" << endl;
    cout << "1. Float" << endl << "2. Double" << endl;
    cin >> float_or_double;
    cout << endl;

    switch(float_or_double){
        case 1: {
            float af, bf;
            cout << "Enter a:" << " ";
            cin >> af;
            cout << endl << "Enter b:" << " ";
            cin >> bf;
            float chyselnykf = (pow(af-bf,4)-(pow(af,4)-4*pow(af,3)*bf+6*pow(af,2)*pow(bf,2)));
            float znamennykf = (pow(bf,4)-4*af*pow(bf,3));
            float resultf = chyselnykf/znamennykf;
            cout << endl << resultf;
            break;
        }    
        case 2: {
            double ad, bd;
            cout << "Enter a:" << " ";
            cin >> ad;
            cout << endl << "Enter b:" << " ";
            cin >> bd;
            double chyselnykd = pow(ad-bd,4)-(pow(ad,4)-4*pow(ad,3)*bd+6*pow(ad,2)*pow(bd,2));
            double znamennykd = pow(bd,4)-4*ad*pow(bd,3);
            double resultd = chyselnykd/znamennykd;
            cout << endl << resultd;
            break;
        }    
        default:{ cout << "Неправильне значення!";}
    }

    return 0;

}