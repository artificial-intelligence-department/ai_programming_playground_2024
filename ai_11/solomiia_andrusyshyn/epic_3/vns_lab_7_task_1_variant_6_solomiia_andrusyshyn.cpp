#include <iostream>
#include <cstdarg>

using namespace std;

int findMinimum(int count, ...)
 {
    int smallest = INT_MAX;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        int current = va_arg(args, int);
        if (current < smallest) {
            smallest = current;
        }
    }

    va_end(args);
    return smallest;
}

int main() {
    cout << "Minimum of first 5 numbers: " << findMinimum(5, 3456, -1, 0, -1200, 76) << "\n";
    cout << "Minimum of second 10 numbers: " << findMinimum(10, 3456, -1, 0, -1200, 76, 777, 778, 19, 20,-2130) << "\n";
    cout << "Minimum of third 12 numbers: " << findMinimum(12, 3456, -1, 0, -1200, 76, 777, 778, 19, 20,-2130, 10739, -10739) << "\n";

    return 0;
}
