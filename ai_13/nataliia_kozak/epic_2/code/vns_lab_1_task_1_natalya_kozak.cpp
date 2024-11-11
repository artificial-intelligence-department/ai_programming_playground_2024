//v7
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
void float_calc(){
    float a = 1000;
    float b = 0.0001;
    float o1, o2, o3, o4, o5;
    o1 = pow(a - b, 3);
    o2 = pow(a, 3);
    o3 = o1 - o2;
    o4 = pow(b, 3) - 3 * a * b * b - 3 * a * a * b;
    o5 = o3 / o4;
    string o1v = to_string(o1);
    string o2v = to_string(o2);
    string o3v = to_string(o3);
    string o4v = to_string(o4);
    string o5v = to_string(o5);
    cout << "\n" << "RESULT with float: " << o5v << endl;
    cout << "Steps: "<< endl;
    cout << "first operation: "<< o1v << endl;
    cout << "second operation: "<< o2v << endl;
    cout << "third operation: "<< o3v << endl;
    cout << "fourth operation: "<< o4v << endl;
}
void double_calc(){
    double a = 1000;
    double b = 0.0001;
    double o1, o2, o3, o4, o5;
    o1 = pow(a - b, 3);
    o2 = pow(a, 3);
    o3 = o1 - o2;
    o4 = pow(b, 3) - 3 * a * b * b - 3 * a * a * b;
    o5 = o3 / o4;
    string o1v = to_string(o1);
    string o2v = to_string(o2);
    string o3v = to_string(o3);
    string o4v = to_string(o4);
    string o5v = to_string(o5);
    cout << "\n" << "RESULT with double: " << o5v << endl;
    cout << "Steps: "<< endl;
    cout << "first operation: "<< o1v << endl;
    cout << "second operation: "<< o2v << endl;
    cout << "third operation: "<< o3v << endl;
    cout << "fourth operation: "<< o4v << endl;
}
int main(){
    //FLOAT
    float_calc();
    //DOUBLE
    double_calc();
    return 0;
}