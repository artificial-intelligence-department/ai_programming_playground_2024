#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

const int option = 38; ///Константна ціла змінна

double function_1(){


float a, b; ///Змінна типу з плаваючою крапкою
int c,d,e;
double g;/// Змінна з подвійною точністю


std::cout << "Enter a: ";
std::cin >> a;
std::cout << "Enter b: ";
std::cin >> b;
std::cout << "Enter c: ";
std::cin >> c;
std::cout << "Enter d: ";
std::cin >> d;
std::cout << "Enter e: ";
std::cin >> e;
std::cout << "Enter g: ";
std::cin >> g;

double array[6] {a, b, static_cast<double>(c), static_cast<double>(d), static_cast<double>(e), g};

for(int i = 0; i < 6; ++i){ ///Використовую цикл для переходу по масиву
    for(int j = 0 ; j < 5; ++j){
        if(array[j] > array[i])
            std::swap(array[i], array[j]);
    }
}


std::cout << "3 lowest: ";
for(int i = 0; i < 3; ++i)
    std::cout << array[i] << ' ';
std::cout << "\n3 biggest: ";
for(int i = 3; i < 6; ++i)
    std::cout << array[i] << ' ';

double Sum;
if((array[0]+array[1]+array[2])*4 < (array[3] + array[4] + array[5]))
    Sum = array[0]+array[1]+array[2] + array[3] + array[4] + array[5];
else if((array[0]+array[1]+array[2])*3 < (array[3] + array[4] + array[5]))
    Sum = (array[0]+array[1]+array[2])/(array[3] + array[4] + array[5]);
else if((array[0]+array[1]+array[2])*2 < (array[3] + array[4] + array[5]))
    Sum = (array[0]+array[1]+array[2])*(array[3] + array[4] + array[5]);
    
    std::cout << '\n';
    std::cout << Sum/option;
    
    return Sum/option;
}




double function_2(double &x){ /// Передача параметра по посиланню

    double matrix[5][5] {x};

    std::random_device rd; 
    std::mt19937 mersenne(rd());

    std::cout << '\n';
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j <5; ++j){
            matrix[i][j] = (matrix[i][j] + option + j - i)*(mersenne()%101);
        }
    }


    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }


return matrix[5][5];

}


double function_3(double tower[][5]){

for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            std::cout << tower[i][j];
        }
    }



    double array[5];
    int smallest;
    for(int j = 0; j < 5; ++j){
        smallest = tower[0][j];
        for(int i = 0; i < 5; ++i){
            if(tower[i][j] < smallest){
                smallest = tower[i][j];
                array[j] = smallest;
            }

        }
    }


    std::cout << "sorted matrix: " << std::endl;
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            std::cout << tower[i][j];
        }
    }

    for(int j = 0; j < 5; ++j){
        double smallest = tower[0][j];
        for(int i = 0; i < 5; ++i){
            if(tower[i][j] < smallest){
                smallest = tower[i][j];
            }
            std::swap(smallest, tower[i][j]);
        }
    }

for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 5; ++j){
            std::cout << tower[i][j];
        }
    }

return *array;
}





int main(){


double x = function_1();

double tower[5][5] {function_2(x)};

double func_3[5][5] = {function_3(tower)};


    return 0;
}
