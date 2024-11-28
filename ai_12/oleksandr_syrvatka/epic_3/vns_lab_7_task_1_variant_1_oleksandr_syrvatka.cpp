#include <iostream>
#include <cstdarg> 

using namespace std;


int sum(int count, ...) {
    int total = 0; 

    va_list args;        
    va_start(args, count); 

    
    for (int i = 0; i < count; ++i) {
        total += va_arg(args, int); 
    }

    va_end(args); 

    return total; 
}

int main() {

    int result1 = sum(3, 1, 2, 3);               
    int result2 = sum(7, 1, 2, 3, 4, 5, 6, 7);   
    int result3 = sum(11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11); 

    cout << "Сума з 3 чисел = " << result1 << endl;
    cout << "Сума з 7 чисел = " << result2 << endl;
    cout << "Сума з 11 чисел = " << result3 << endl;

    return 0;
}
