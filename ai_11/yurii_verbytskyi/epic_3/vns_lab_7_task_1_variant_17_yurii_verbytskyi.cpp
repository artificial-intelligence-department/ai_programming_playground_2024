#include <iostream>
#include <conio.h>
#include <stdarg.h>
#include <cmath>

using namespace std;

// алгоритм ератосфена для вирахування простих чисел
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }

    return true;
}


void prost(int a, int b) { 
    for (int i = a; i <= b; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    } cout << endl;
}


int main(){
    // пари інтервалів
    int a, b;
    int c, d;
    int e, f;

    cin >> a >> b;
    cin >> c >> d;
    cin >> e >> f;
    
    
    prost(a, b); 
    prost(c, d);
    prost(e, f);
    return 0;
}
