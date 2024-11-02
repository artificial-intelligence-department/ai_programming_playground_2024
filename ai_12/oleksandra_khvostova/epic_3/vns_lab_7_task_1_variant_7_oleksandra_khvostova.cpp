#include <iostream>
#include <cstdarg>
#include <limits>

using namespace std;

template <typename type>
type min(int count, ...) {
    va_list args;
    va_start(args, count);

    type min_val = numeric_limits<type>::max();

    for (int i = 0; i < count; ++i) {
        type val = va_arg(args, type);
        if (val < min_val) {
            min_val = val;
        }
    }

    va_end(args);
    return min_val;
}

int main() {
    cout << "Minimum of 5 ints: " << min<int>(5, 10, 20, 3, 40) << endl;
    cout << "Minimum of 10 doubles: " << min<double>(10, 12.3, 44.5, 22.1, 37.7, 30.5, 567.9, 67.4, 4.5, 89.2) << endl;
    cout << "Minimum of 12 doubles: " << min<double>(12, 12.3, 44.5, 78.9, 1.1, 22.6, 37.8, 30.5, 567.9, 67.4, 4.5, 123.1) << endl;

    return 0;
}
