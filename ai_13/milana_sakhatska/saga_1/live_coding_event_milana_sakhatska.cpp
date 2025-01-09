#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int VARIANT = 77;

double finction_1() {
    //введення даних
    float a, b;
    int c, d ,e;
    double f;

    cout << "введіть  a, b:";
    cin >> a >> b;
    cout <<  "введіть c, d, e";
    cin >> c >> d >> e;
    cout << "введіть f"; 
    cin >> f;

    //збереження значень у векторі
    vector<double> values = {a, b, c, d, e, f};
    //сортування
    sort(values.begin(),
    values.end());

    //три найбільші найменші значення
    double sum_min = values[0] + values[1] + values[2];
    double sum_max = values[3] + values[4] +values[5];
     if (sum_min == 0){
        cout <<"помилка"
     }
    double result;
    if (sum_max > sum_min * 4) {
        result = sum_max + sum_min;
    } else if (sum_max > sum_min * 3){ 
        result = sum_max / sum_min; 
    } else if {
        result = (sum_max > sum_min * 2);
    } else if (){
         result = sum_max - sum_min;
    } else {
         result=0;
    }
    // вивід даних
     cout << "результат: " << result << endl;
     return result;

     int main() {
        double x = function_1()
        return 0;
     }

}