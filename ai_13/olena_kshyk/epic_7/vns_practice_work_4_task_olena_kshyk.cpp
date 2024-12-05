#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << "+-------+---------+" << endl;
    cout << "| Число | Квадрат |" << endl;
    cout << "+-------+---------+" << endl;

    for (int i = 1; i <= 10; i++) 
        cout << "| " << setw(5) << i << " | " << setw(7) << i * i << " |" << endl;

    cout << "+-------+---------+" << endl;

    return 0;
}
