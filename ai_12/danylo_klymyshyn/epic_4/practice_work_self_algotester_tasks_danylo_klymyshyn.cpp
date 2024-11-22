#include <iostream>
#include <cmath>
#include <iomanip>


struct Coordinates{
    double x;
    double y;
};


int main(){

Coordinates M1, M2, P, P0;

std::cin >> P.x >> P.y >> M1.x >> M1.y >> M2.x >> M2.y; 


if(M1.x == M2.x){
    P0.x = M1.x;
    P0.y = P.y;
}
else if(M1.y == M2.y){
    P0.y = M1.y;
    P0.x = P.x;
}
else{
    double A = M2.y - M1.y;
    double B = M1.x - M2.x;
    double C = M2.x * M1.y - M1.x * M2.y;

    P0.x = (B*(B*P.x-A*P.y)-A*C)/(A*A+B*B);
    P0.y = (A*(-B*P.x+A*P.y)-B*C)/(A*A+B*B);
}


bool is_on_line = (std::min(M1.x, M2.x) <= P0.x && P0.x <= std::max(M1.x, M2.x)) && (std::min(M1.y, M2.y) <= P0.y && P0.y <= std::max(M1.y, M2.y));

double distance;

if(is_on_line)
    distance = sqrt(pow((P0.x-P.x), 2) + pow((P0.y-P.y), 2));
else{
    double d1 = sqrt(pow((P.x-M2.x), 2)+pow((P.y-M2.y), 2));
    double d2 = sqrt(pow((P.x-M1.x), 2)+pow((P.y-M1.y), 2));
    distance = std::min(d1, d2);
}


std::cout << std::fixed << std::setprecision(4) << distance << std::endl;

    return 0;
}