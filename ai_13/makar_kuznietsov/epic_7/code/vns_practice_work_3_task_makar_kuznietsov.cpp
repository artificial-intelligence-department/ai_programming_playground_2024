// variant 15
#include <cmath>
#include <iostream>
void parVol();
int main()
{
    parVol();
    return 0;
}

void groceryCost();

void parVol()
{
    float a, b, c;
    std::cout << "Обчислення об'єму паралелепіпеда.\nВведіть в одному рядку довжину, ширину і висоту паралелепіпед (в "
                 "сантиметрах).\nЧисла розділяйте пропусками.\nПісля введення останнього числа натискуйте <Enter> ";
    std::cin >> a >> b >> c;
    std::cout << "Об'єм паралелепіпеда" << a * b * c << "см.куб.";
    groceryCost();
}

void groceryCost()
{
    double tom, cucum, dill;
    std::cout << "Enter cost of tomato: ";
    std::cin >> tom;
    std::cout << "Enter cost of cucumber: ";
    std::cin >> cucum;
    std::cout << "Enter cost of dill: ";
    std::cin >> dill;

    int t_a, c_a, d_a;
    std::cout << "How many tomatoes: ";
    std::cin >> t_a;
    std::cout << "How many cucumbers: ";
    std::cin >> c_a;
    std::cout << "How many bunches of dill: ";
    std::cin >> d_a;

    std::cout << "You need to pay: " << tom * t_a + cucum * c_a + dill * d_a;
}
