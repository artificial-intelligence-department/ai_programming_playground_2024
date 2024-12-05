//Розробити алгоритм, що розгалужується для
//розв’язання задачі номер 22

#include <iostream>
#include <vector>
#include <cmath>

int main(){
    int point[5]={0};
    int R=5, a=0, b=2, x, y;
    bool are = 0;
    for (int i=0; i<5; i++){
        std::cout << "Введіть координати точки " << i+1 << " : ";
        std::cin >> x >> y;
        if((pow((x-a), 2) + pow((y-b), 2)) <= pow(R,2)){
            point[i] = i+1;
        }
    }
    for(int i=0; i<5; i++){
        if(point[i]!=0){
            std::cout << "Точка " << point[i] << " належить колу радіусом " << R << " з координатами центру (" << a << "," << b << ")\n";
            are = 1;
        }
    }
    if(are==0){
        std::cout << "Ви не ввели точок, які б належили колу радіусом " << R << " з координатами центру (" << a << "," << b << ")\n";
    }
    return 0;
}