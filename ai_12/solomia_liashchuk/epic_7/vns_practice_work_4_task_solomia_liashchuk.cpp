#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(time(0));
    double sum;

    for (int i = 0; i < 10; i++) 
    {
        int random_number = 1 + rand() % 10;
        cout << "Випадкові 10 чисел: " << random_number << endl;
        sum += random_number;
    }

    double average = sum / 10; 

    cout << endl;
    cout << "Середнє арифметичне: " << average << endl;


    return 0;
}