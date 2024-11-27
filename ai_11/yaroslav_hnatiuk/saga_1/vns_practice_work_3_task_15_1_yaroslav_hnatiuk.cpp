#include <iostream>

using namespace std;

int main() {
    float a, b, c; 

    cout << "Обчислення об'єму паралелепіпеда." << endl;
    cout << "Введіть в одному рядку довжину, ширину і висоту паралелепіпеда (в сантиметрах)." << endl;
    cout << "Числа розділяйте пропусками: " << endl;
    cout << "Після введення останнього числа натискуйте <Enter> ";
    
    cin >> a >> b >> c;

    float volume = a * b * c;

    cout << "Об'єм паралелепіпеда: " << volume << " см. куб." << endl;

    return 0;
}

