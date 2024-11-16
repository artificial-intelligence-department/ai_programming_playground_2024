#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for(int i = 3 ; i < 200; i+= 3){
            sum += i;
    }
    cout << "Сума цілих чисел кратних 3 і менших за 200 = " << sum ;

    return 0;

}