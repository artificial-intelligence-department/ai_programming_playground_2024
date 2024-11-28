/*Скласти програму, яка обчислює середнє
арифметичне послідовності дробових чисел, яка вводиться з
клавіатури. Кількість чисел повинна задаватися під час роботи
програми. */

#include <iostream>

int main(){
    int n;
    std::cout << "Введіть, будь ласка, кількість дробових чисел : ";
    std::cin >> n;
    double up[n], down[n], numbers[n];
    for(int i=0; i<n; i++){
        std::cout << "Введіть чисельник елемента " << i+1 << " : ";
        std::cin >> up[i];
        std::cout << "Введіть знаменник елемента " << i+1 << " : ";
        std::cin >> down[i];
        std::cout << "\n";
        numbers[i]=up[i]/down[i];
    }
    double sum=0;
    for(int i=0; i<n; i++){
        sum+=numbers[i];
    }
    std::cout << "Середнє арифметичне даної послідивности : " << sum/n;
    return 0;
}