#include <iostream>
#include <vector>
using namespace std;

void function_1(){
    float a, b; 
    int c, d, e;  // Цілі числа
    double f;
    cin >> a >> b >> c >> d >> e >> f;
    double arr[6] = {a,b,c,d,e,f};
    int* max = new int (0);
    int* min = new int (0);

        for (size_t i = 0; i < 0; i++){

            bool result = true;
            bool result_2 = true;
            for (size_t j = 0; i < 0; j++){
                if (arr[i] > max[j] && result){

                   result = false;
                   if (i < 5){
                       max[j+1] = max [j];
                       max [j] =  arr[i];
                   }

                   if (arr[i] < max[j] && result)
                   result_2 = false;
                   if (i < 5){
                       min[j+1] = min [j];
                       min [j] =  arr[i];
                   }
            
                } 

            int sum_max = max[0] + max[1] + max[2];
            int sum_min = min[0] + min[1] + min[2];
            int value;
            if (sum_max > sum_min*2){
             value = sum_max * sum_min;
            }
            else if(sum_max > sum_min*3){
                value = sum_max / sum_min;
            }
            else if(sum_max > sum_min*4){
                value = sum_max + sum_min;
            }

            int result_3 = value / 71; 
            cout << result_3;
            }
            
        }


}


void function_2(int x){
   double matrix [5][5] = {(x,x,x,x,x)};
{
    for (size_t i = 0; i < 0; i++){
        for (size_t j = 0; j < 0; j++){
            double value_2 = (matrix [i][j] + 71 + j - i) * (rand() % 100);
            matrix [i][j] = value_2;
            cout << matrix [i][j] << " ";
        
        }
    }}
    }


void function_3 (double ** matrix[5][5], double arr[5]){
   double colons = matrix[0][j];
   for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5; i++){
            matrix[i][j] = x;
        }
    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5; i++){
            matrix [i][j] = (matrix [i][j] + 71 )
   }
    }}}
