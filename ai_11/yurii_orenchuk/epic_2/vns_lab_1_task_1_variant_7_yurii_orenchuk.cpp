#include <iostream>
#include <math.h>
using namespace std;

int main(){
    double a_db = 1000.0;
    double b_db = 0.0001;

    double top_db = pow((a_db - b_db), 3) - pow(a_db, 3);
    double bottom_db = pow(b_db, 3) - 3 * a_db * pow(b_db, 2) - 3 * pow(a_db, 2) * b_db;
    double res_db = top_db / bottom_db;
    cout << "top: " << top_db << endl;
    cout << "bottom: " << bottom_db << endl;
    cout << "double result: " << res_db << endl;


    float a_flt = 1000.0;
    float b_flt = 0.0001;

    float top_flt = pow((a_flt - b_flt), 3) - pow(a_flt, 3);
    float bottom_flt = pow(b_flt, 3) - 3 * a_flt * pow(b_flt, 2) - 3 * pow(a_flt, 2) * b_flt;
    float res_flt = top_flt / bottom_flt;
    cout << "top: " << top_flt << endl;
    cout << "bottom: " << bottom_flt << endl;
    cout << "float result: " << res_flt;

    return 0;
}