#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

int main(){
    float distance;
    float time;
    int mins;
    int sec;
    float avgSpeed;
    std::cout << "Enter distance in meters > ";
    std::cin >> distance;
    std::cout << "Enter time(minuts.seconds) > ";
    std::cin >> time;
    mins = time;
    sec = 100 * (time - float(mins));
    std::cout << "Time of running : " << (mins * 60 + sec) << " seconds\n";
    avgSpeed = distance / float(mins * 60 + sec) * 3.6;
    std::cout << "Avarage speed per hour: " << avgSpeed << " km\n\n\n"; 

    float r;
    std::cout << "Enter radius of sphere : ";
    std::cin >> r;
    std::cout << "Volume of sphere is " << (3.0/4 * M_PI * r * r *r) << std::endl;
    std::cout << "Square of sphere is " << (M_PI * 4 * r *r) << std::endl;
    return 0;
}