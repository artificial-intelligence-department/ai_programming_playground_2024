#include <iostream>

using namespace std;

//Знайти суму цілих додатніх чисел, більших 20, менших 100 і кратних 3

int main(){

int s;

for(int i = 20; i<100;i+=3){
    while(true){
        if(i % 3 == 0){
            break;
        }
        ++i;
    }
    s+=i;
}

cout << s;

    return 0;
}