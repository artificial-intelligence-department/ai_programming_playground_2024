#include <iostream>
#include <math.h>
using namespace std;

int main(){
int choice;
cout << "Введіть float - 1 чи double - 2: ";
cin >> choice;
if (choice == 1){
    float a1 = 100;
    float b1 = 0.001;
    float sum1_1 = a1+b1;
    float st1_4 = pow(sum1_1,4);
    float st_a1_4 = pow(a1,4);
    float st_a1_3 = pow(a1,3);
    float st_a1_2 = pow(a1,2);
    float st_b1_2 = pow(b1,2);
    float st_b1_3 = pow(b1,3);
    float st_b1_4 = pow(b1,4);
    float sum1_2 = (st_a1_4 + 4 * st_a1_3 * b1);
    float sum1_3 = (6 * st_a1_2 * st_b1_2 + 4 * a1 * st_b1_3 + st_b1_4);
    float result1 = (st1_4 - sum1_2) / sum1_3;
    cout << "Float result: " << result1 << endl;}
else if (choice==2){
    double a2 = 100;
    double b2 = 0.001;
    double sum2_1 = a2+b2;
    double st2_4 = pow(sum2_1,4);
    double st_a2_4 = pow(a2,4);
    double st_a2_3 = pow(a2,3);
    double st_a2_2 = pow(a2,2);
    double st_b2_2 = pow(b2,2);
    double st_b2_3 = pow(b2,3);
    double st_b2_4 = pow(b2,4);
    double sum2_2 = (st_a2_4 + 4 * st_a2_3 * b2);
    double sum2_3 = (6 * st_a2_2 * st_b2_2 + 4 * a2 * st_b2_3 + st_b2_4);
    double result2 = (st2_4 - sum2_2) / sum2_3;
    cout << "Double result: " << result2 << endl;}
    return 0;
}
