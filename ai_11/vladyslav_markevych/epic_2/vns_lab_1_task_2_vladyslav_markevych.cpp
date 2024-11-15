#include <iostream>

using namespace std;

int main(){

    float n;
    double m;

    float first, second, third;
    double first_d, second_d, third_d;

    cout<<"Введіть n: "<<endl;
    cin>>n;
    cout<<"Введіть m: "<<endl;
    cin>>m;

    first = - -m-++n;
    first_d = - -m-++n;

    second = m*n<n++;
    second_d = m*n<n++;

    third = n-- > m++;
    third_d = n-- > m++;

    cout<<"Результат 1(float): "<<first<<endl;
    cout<<"Результат 1(double): "<<first_d<<endl;

    cout<<"Результат 2(float): "<<second<<endl;
    cout<<"Результат 2(double): "<<second_d<<endl;

    cout<<"Результат 3(float): "<<third<<endl;
    cout<<"Результат 3(double): "<<third_d<<endl;

    return 0;
}