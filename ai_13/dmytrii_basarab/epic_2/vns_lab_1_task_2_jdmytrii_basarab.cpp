#include <iostream>

using namespace std;

int main() {
    int n,m;
    n = 4;
    m = 0;
    int first = m-++n;/*так як нема такого оператора m- то воно розуміє шо це вираз m - ++n
    де ++n оператор префіксний то воно виконує цю дію перед основною дією -*/ 
    bool second = ++m > --n;//відповідно перше робить m+1 i n-1 а потім вже порівнює і значення або істинне або хибне тому bool
    bool third = --n < ++m;//аналогічно
    cout << first << " " << second << " " << third;
    return 0;
}