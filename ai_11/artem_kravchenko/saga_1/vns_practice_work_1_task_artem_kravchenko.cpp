 #include <iostream>
 #include <cmath> // для використання pow, cos, sin

 using namespace std;

 int main(){
   // ініціалізація змінних
    double x = 1.45;
    double y = -1.22;
    double z = 3.5;
    double p = 3.14; 
   // обчислення функцій
    double b = 1 + (pow(z, 2) / 3 + (pow(z, 2) / 5));

    double a = 2 * cos(x -(p / 6)) * b / (0.5 + pow(sin(y), 2));
   // вивід результатів
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
 }