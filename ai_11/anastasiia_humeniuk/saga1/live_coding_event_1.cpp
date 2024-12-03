#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int VARIANT = 7;
double function_1(){
        double a, b;
        int c, d, e;
        double f;

        cin >> a >> b;
        cin >> c >> d >> e;
        cin >> f;

        double numbers[6] = {a, b, static_cast<double> (c), static_cast<double> (d), static_cast<double> (e), f};
        sort (numbers, numbers +6);

        double min[3] = {numbers[0], numbers[1], numbers[2]};
        double max[3] = {numbers[3], numbers[4], numbers[5]};
            
        double result = 0;
        double sum_min = numbers[0]+ numbers[1]+ numbers[2];
        double sum_max = numbers[3] + numbers[4] + numbers[5];
        if (sum_max > (sum_min*2)){
            result = sum_min * sum_max;}
        else if (sum_max > (sum_min*3)){
            result = sum_min / sum_max;}
        else if (sum_max > (sum_min*4)){
            result = sum_min + sum_max;}
        else 
            cout << "Error" << endl;
               
    
        result /= VARIANT;
        return result;
    }

void function_2(int& x, int matrix[5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] = x;
        }
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matrix[i][j] =  matrix[i][j] + VARIANT + i + j + rand() % 100;
        }
    }

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
/*
void function_3(int matrix[5][5]){
int Colmin[5];
for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - 1; j++) {
            for (int k = 0; k < 5 - j - 1; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    swap(matrix[i][k], matrix[i][k + 1]);
                }
            }
        Colmin[i] = matrix[i][j];}
        cout <<  Colmin[i] << endl;
    }
    
}*/
int main()
{
    int array[5][5];
    int x = function_1();
    function_2(x, array);
    //cout <<  function_1();
     //function_3(array);
    return 0;
}