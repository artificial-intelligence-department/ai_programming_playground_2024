#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Using float:"<< endl;
    float a = 1000;
    float b = 0.0001;
    float d;
    float d1;
    float d2;
    float resault;
    
    d = pow((a-b), 3);
    
    d1 = pow(a, 3) - 3*pow(a, 2)*b;
    
    d2 = pow(b, 3) - 3*a*pow(b, 2);
    
    resault = (d - d1)/d2;
    cout << "resault = " << resault << endl;
    
    cout << "Using double:"<< endl;
    double dub_a = 1000;
    double dub_b = 0.0001;
    double dub_D;
    double dub_D1;
    double dub_D2;
    double dub_resault;
    
    dub_D = pow((dub_a-dub_b), 3);

    dub_D1 = pow(dub_a, 3) - 3*pow(dub_a, 2)*dub_b;

    dub_D2 = pow(dub_b, 3) - 3*dub_a*pow(dub_b, 2);
    
    resault = (dub_D - dub_D1)/dub_D2;
    cout << "resault = " << dub_resault << endl;    
    
    return 0;
}