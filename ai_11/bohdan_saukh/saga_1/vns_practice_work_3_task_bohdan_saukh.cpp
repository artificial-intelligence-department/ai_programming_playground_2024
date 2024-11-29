#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    cout << "Обчислення опору електричного ланцюга при паралельному з'єднанні елементів." << endl;
    cout << "Введіть початкові дані:" << endl;

    double R1, R2;

    cout << "Величина першого опору (Ом) > ";
    cin >> R1;

    cout << "Величина другого опору (Ом) > ";
    cin >> R2;
    
    double res = 1 / ((1 / R1) + (1 / R2));
    
    printf("Опір ланцюга: %.2f Ом\n", res);
    
    cout << endl << "Завдання 2: " << endl;
    
    int pages = 948;
    int words_per_page = 30;
    int letters_per_word = 5;
    double width = 2.0; //ширина букви

    int words = pages * words_per_page;

    double total_length = words * letters_per_word * width;

    cout << "Кількість українських слів у словнику: " << words << endl;
    cout << "Довжина всіх слів: " << total_length << " мм" << endl;


    return 0;
}