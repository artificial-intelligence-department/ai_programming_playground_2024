#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        int num = rand() % 10 + 1;
        cout << num << " ";
        sum += num;
    }
    cout << endl;

    cout << "Середнє арифметичне: " << sum / 10 << endl;

    return 0;
}
