#include <iostream>
#include <cmath>
#include <cstdarg> 

using namespace std;

bool is_square(int num) {
    int x = sqrt(num); 
    return x * x == num;
}

int kvadr(int count, ...) {
    int counter = 0;
    va_list args; 
    va_start(args, count); 

    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        if (is_square(num)) { 
            counter++;
        }
    }

    va_end(args); 
    return counter; 
}

int main() {
    cout << "Кількість точних квадратів для 3: " << kvadr(3, 4, 8, 16) << endl;
    cout << "Кількість точних квадратів для 7: " << kvadr(7, 3, 4, 9, 15, 16, 25, 81) << endl;
    cout << "Кількість точних квадратів для 11: " << kvadr(11, 5, 9, 10, 16, 18, 25, 30, 36, 40, 49, 64) << endl;

    return 0;
}
