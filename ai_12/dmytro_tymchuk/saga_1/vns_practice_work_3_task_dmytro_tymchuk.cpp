//vns task3 V-14
#include<iostream>
#include<math.h>
using namespace std;

namespace Geo {
    double circle_length(double r)
    {
        return 2 * M_PI * r;
    }

    double circle_area(double r)
    {
        return M_PI * r * r;
    }

    double rectangle_area(double l, double h)
    {
        return l * h;
    }
}

double resistance_calculation(double r1, double r2)
{
    return pow((1 / r1) + (1 / r2), -1);
}

int main()
{
    double r, h;
    cout<<"Обчислення площі поверхні циліндра."<<endl;
    cout<<"Введіть початкові дані: "<<endl;
    cout<<"Введіть радіус основи циліндра(cм): ";
    cin>>r;
    cout<<"Введіть радіус висоти циліндра(см): ";
    cin>>h;
    printf("Площа поверхні циліндра: %.2lf\n\n", Geo::rectangle_area(Geo::circle_length(r), h) + 2 * Geo::circle_area(r));

    int r1, r2;
    cout<<"Обчислення опору електричного ланцюга."<<endl;
    cout<<"Введіть початкові дані: "<<endl;
    cout<<"Введіть опір першого резистора: ";
    cin>>r1;
    cout<<"Введіть опір другого резистора: ";
    cin>>r2;
    printf("Площа електричного ланцюга: %.2lf\n", resistance_calculation(r1, r2));
    return 0;
}