#include <iostream>
using namespace std;

int main(){
    int summ = 0;
    for(int i=1; i<200; i+=2){
        summ += i;
    }
    cout << "Cума цілих додатніх непарних чисел, менших 200: " << summ << endl;
    return 0;
}
