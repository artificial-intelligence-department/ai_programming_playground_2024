#include <stdio.h>
#include <iostream>

// Знайти суму цілих додатніх чисел, більших 20, менших 100 і кратних 3

using namespace std;

int main(){
    int a;
    for (int i = 21; i < 100; i += 3)
    {
        a += i;
    }
    cout << a;
}











