#include <iostream>
#include <cstdarg>

using namespace std;

void Convertation(int num, ...) 
{
    va_list args;
    va_start(args, num);

    cout << "Перетворення чисел у вісімкову систему: ";
    for (int i = 0; i < num; i++) 
    {
        int number = va_arg(args, int);
        cout << dec << number << " -> " << oct << number << "  ";  
    }
    cout << endl;

    va_end(args);  
}

int main() 
{
    Convertation(3, 7, 1, 100);
    Convertation(5, 9, 26, 30, 49, 16);
    Convertation(8, 19, 32, 83, 65, 94, 78, 27, 51);

    return 0;

}
