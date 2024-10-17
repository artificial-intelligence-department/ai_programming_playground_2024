#include<iostream>
#include<math.h>

using namespace std;

int main(){
    float aF = 100;
    float bF = 0.001;
    float upperLeftF = pow((aF + bF), 4);
    float upperRightF = pow(aF, 4) + 4 * pow(aF, 3) * bF + 6 * pow(aF, 2) * pow(bF, 2); 
    float downF = 4 * aF * pow(bF, 3) + pow(bF, 4);
    float resultF = (upperLeftF - upperRightF) / downF;

    double aD = 100;
    double bD = 0.001;
    double upperLeftD = pow((aD + bD), 4);
    double upperRightD = pow(aD, 4) + 4 * pow(aD, 3) * bD + 6 * pow(aD, 2) * pow(bD, 2); 
    double downD = 4 * aD * pow(bD, 3) + pow(bD, 4);
    double resultD = (upperLeftD - upperRightD) / downD;

    cout << "Float: " << resultF << endl;
    cout << "Double: " << resultD << endl;
}