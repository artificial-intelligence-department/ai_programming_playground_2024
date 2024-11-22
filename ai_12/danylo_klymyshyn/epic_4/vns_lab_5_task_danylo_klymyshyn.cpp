#include <iostream>

int calculate(int **array){
    double S = 0;
    short counter = 0, n = 0;
    for(int i = 0; i < 6; ++i){
            S += array[i][0];
            ++counter;
    }
    double S_A = S/counter;
    
    for(int j = 1; j < 6; ++j){
        for(int i = 0; i < 6; ++i){
            if(array[i][j] > S_A)
                ++n;
        }
    }    

    return n;
    }
int main(){

int **array = new int*[6];
for(int i = 0; i < 6; ++i){
    array[i] = new int[6];
}


for(int i = 0; i < 6; ++i){
    for(int j = 0; j < 6; ++j){
        std::cin >> array[i][j];

    }
}

std::cout << "N = " << calculate(array);

for(int i=0; i < 6; ++i){
    delete[] array[i];
}

delete[] array;
    return 0;
}