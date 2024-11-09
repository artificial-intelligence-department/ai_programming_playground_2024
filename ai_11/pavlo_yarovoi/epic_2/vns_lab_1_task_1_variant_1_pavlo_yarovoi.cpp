#include <iostream>
#include<cmath>

using namespace std;
int main()
{
    float AF=1000;
    float BF=0.0001;
    float NumF = pow(AF+BF, 2) - (pow(AF, 2) + 2 * AF * BF);
    float DeNomF = pow(BF, 2);
    float resultF = NumF/DeNomF;
    
    double AD=1000;
    double BD=0.0001;
    double NumD = pow(AD+BD, 2) - (pow(AD, 2) + 2 * AD * BD);
    double DeNomD = pow(BD, 2);
    double resultD = NumD/DeNomD;
    
    cout<< "\n\nUsing float: \n\n"<<"Numerator: "<< NumF << endl<< "Denominator: "<< DeNomF << endl << "Result: " << resultF << endl << endl;
    cout<< "Using double: \n\n"<<"Numerator: "<< NumD << endl<< "Denominator: "<< DeNomD << endl << "Result: " << resultD << endl << endl;
    return 0;
}