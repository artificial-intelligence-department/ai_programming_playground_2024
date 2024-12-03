#include <iostream>

using namespace std;

double function_1(){
const double num_of_var = 4;
    float a, b; 
    cin >> a >> b;
    int c, d, e;
    cin >> c >> d >> e;
    double f;
    cin >> f;
    int size = 6;
    double el[6] = {a, b, c, d, e, f};
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (el[j] > el[j + 1]) {
                swap(el[j], el[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    double sum_of_max = 0;
    double sum_of_min = 0;
    for(int i = 0; i < 3; i++){
        sum_of_min += el[i];
    }

    for(int i = 3; i < 6; i++){
        sum_of_max += el[i];
    }

    double result_of_1 = 0;

    if(sum_of_max > (sum_of_min * 4)){
        result_of_1 = sum_of_max + sum_of_min;
    }
    else if(sum_of_max > (sum_of_min * 3)){
        result_of_1 = sum_of_max / sum_of_min;
    }

    else if(sum_of_max > (sum_of_min * 2)){
        result_of_1 = sum_of_max * sum_of_min;
    }
    
    else cout << "Check the input" << endl;
    
    double x = result_of_1 / num_of_var;
    return x;
}





int main(){
    double x = function_1();
    cout << function_1();
    return 0;
}