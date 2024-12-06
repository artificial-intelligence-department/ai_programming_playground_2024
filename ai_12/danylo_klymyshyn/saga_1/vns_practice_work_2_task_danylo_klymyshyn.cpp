#include <iostream>
#include <cmath>

int main(){


double xstart = 0.5, xend = 3.1;
double astart = -0.1, aend = -1.4; //Ініціалізовую всі змінні
double hx = 0.21, ha = 0.1;
double b = 1.5;

double y;

double x = xstart;
double a = astart;

std::cout << "X: \t A: \t Y: " << std::endl; //Шапка
while(a >= aend && x <= xend){  //Табулюю значення від початкового до кінцевого
    if(x < b){
        y = sin(fabs(a*x + pow(b, a))); //В залежності від x задаю різне значення у
    }
    else{
        y = cos(fabs(a*x - pow(b, a)));
    }
    std::cout << x << " \t " << a << " \t " << y << std::endl; //Вивід результатів підрахунків

    a-=ha; //Крок для a
    x+=hx;
}

    return 0;
}