#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

//ф-я зі змінною кількістю параметрів (еліпсис)
int kvadr(int numArgs, ...) { 
    va_list args;
    va_start(args, numArgs);

    int count = 0;
    for (int i = 0; i < numArgs; ++i) {
        int num = va_arg(args, int);
        int sqrtNum = static_cast<int>(sqrt(num));
        if (sqrtNum * sqrtNum == num) {
            ++count;
        }
    }

    va_end(args);
    return count;
}

int main() {
    cout << "Кількість точних квадратів (3 параметри): " << kvadr(3, 2, 4, 9) << endl;

    cout << "Кількість точних квадратів (7 параметрів): " << kvadr(7, 1, 4, 8, 9, 16, 23, 25) << endl;

    cout << "Кількість точних квадратів (11 параметрів): " << kvadr(11, 3, 6, 9, 12, 16, 25, 36, 48, 49, 64, 100) << endl;

    return 0;
}
