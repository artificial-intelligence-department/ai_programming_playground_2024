#include <iostream>
#include <cstdlib>
#include <ctime>

int function_1()  {
    return 10;
}

void function_2(int& x) {

int matrix[5][5];
for (int i = 0; i<5;++i) {
    for (int j = 0; j<5; ++j){
        matrix[i][j] = x;
    }
}

std::cout << "Оновлена матриця: " << std::endl;
for(int i = 0; i<5; ++i) {
    for (int j = 0; j < 5; ++j) {
        std::cout << matrix[i][j] << "\t";
    }
    std::cout << std::endl;
}
}


int main()  {

std::srand(std::time(0));


int x = function_1();

return 0;

}