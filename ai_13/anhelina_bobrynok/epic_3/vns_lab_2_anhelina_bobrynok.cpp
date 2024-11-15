#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    for (int i = 1; i < 200; i += 2) {
        sum += i;
    }

    cout << "Сума цілих додатніх непарних чисел, менших 200, дорівнює: " << sum << endl;
    return 0;
}
