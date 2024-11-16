#include <iostream>
#include <stdio.h> //з першого епіку взяв
#include <cmath>

   const float a_f = 1000;
   const float b_f = 0.0001;

   const double a_d = 1000;
   const double b_d = 0.0001; //використав константи

using namespace std;

int main() {
float first_action_f = pow((a_f - b_f), 3 );
printf ("Float first printf: %f\n", first_action_f); 
cout << "Float first cout: " << first_action_f << endl;
cout << endl; /*cout виводить значення 1e+09 шо нам взагалі
 не підходить тому використовуєм printf
  і вставки для точності, а точність обрахунків вже буде залежати від місткості 
  float чи double */

float second_action_f = pow(a_f, 3);

float third_action_f = 3*a_f*pow(b_f, 2);

float fourth_action_f = second_action_f - third_action_f;

float fifth_action_f = first_action_f - fourth_action_f;

float sixth_action_f = pow(b_f, 3);

float seventh_action_f = 3*b_f*pow(a_f, 2);

float eigth_action_f = sixth_action_f - seventh_action_f;

float result_f = fifth_action_f / eigth_action_f;
printf("Float result printf: %.15f\n", result_f);
cout << "Float result cout: " << first_action_f << endl;
cout << endl;




double first_action_d = pow((a_d - b_d), 3 );
printf ("Double first printf: %f\n", first_action_d); 
cout << "Double first cout: "<< first_action_d << endl;
cout << endl;

double second_action_d = pow(a_d, 3);

double third_action_d = 3*a_d*pow(b_d, 2);

double fourth_action_d = second_action_d - third_action_d;

double fifth_action_d = first_action_d - fourth_action_d;

double sixth_action_d = pow(b_d, 3);

double seventh_action_d = 3*b_d*pow(a_d, 2);

double eigth_action_d = sixth_action_d - seventh_action_d;

double result_d = fifth_action_d / eigth_action_d;
printf("Double result printf: %.15f\n", result_d);
cout << "Double result cout: " << first_action_f << endl;
cout << endl;
return 0;
} /* Висновок: всі обрахунки будуть точні якшо ми вкажемо в printf кількість знаків 
після коми та чи вміщається число в тип даних(в нас це double)
я старався роздробити кожну дію для більш точного результату*/