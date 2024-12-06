#include <iostream>
#include <cstdarg> 
#include <cmath>   
using namespace std;


bool is_triangle(int x, int y, int z) {
    return (x + y > z) && (x + z > y) && (y + z > x);
}

int triangle(int count, ...) {
    int valid_triplets = 0; 
    va_list args;
    va_start(args, count);

    for (int i = 0; i <= count - 3; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);
        int z = va_arg(args, int);

        if (is_triangle(x, y, z)) {
            valid_triplets++;
        }


        if (i < count - 3) {
            va_end(args);
            va_start(args, count);
            for (int j = 0; j <= i; j++) va_arg(args, int);
        }
    }

    va_end(args);
    return valid_triplets;
}

int main() {
    
    cout << "Test case 1 (3 numbers): " << triangle(3, 3, 4, 5) << endl; 
    cout << "Test case 2 (9 numbers): " << triangle(9, 1, 2, 3, 4, 5, 6, 7, 8, 9) << endl; 
    cout << "Test case 3 (11 numbers): " << triangle(11, 10, 15, 20, 5, 7, 8, 1, 2, 3, 9, 12) << endl; 

    return 0;
}
