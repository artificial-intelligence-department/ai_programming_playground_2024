#include <iostream>
using namespace std;

int main() {
    unsigned int a, b;
    cin >> a >> b;

    int count_num = 0;
    int count_unlucky = 0;

    cout << "C243 ";

    for (int i = a; i <= b; i++) {
        if (i%2 == 1 || (i/10)%2 == 1 || (i/100)%2 == 1 || (i/1000)%2 == 1 || (i/10000)%2 == 1 || (i/100000)%2 == 1) {
            count_unlucky++;
            continue;
        }
        cout << i << " ";
        count_num = count_num + 1;
        if (count_num > 10000) {
            break;
        }
    }

    if(count_num > count_unlucky) {
            
        }

    if (count_num == 0) {
        cout << "none" << endl;
        return 0;
    } 

    return 0;
}