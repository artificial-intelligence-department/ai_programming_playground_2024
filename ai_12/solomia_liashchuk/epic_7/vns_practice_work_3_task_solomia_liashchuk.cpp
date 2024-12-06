#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double notebook;
    double cover;
    int sets; 

    cout << "Введіть ціну зошита: " << endl;  
    cin >> notebook;                          
    cout << "Введіть ціну обкладинки" << endl;
    cin >> cover;
    cout << "Введіть кількість комплектів" << endl;
    cin >> sets;

    double result = (notebook + cover) * sets;

    cout << "Вартість покупки: " << result << endl; 


    int r = 9;
    const double PI = 3.14; 

    double volume = (4.0 / 3.0) * PI * pow(r, 3);
    double surface_area = 4 * PI * pow(r, 2);

    cout << "Об'єм кулі: " << volume << endl;
    cout << "Площа поверхні кулі: " << surface_area << endl;

    return 0;

}