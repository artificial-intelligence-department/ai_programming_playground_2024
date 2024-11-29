#include <iostream>
#include <cmath>

double CylinderVolume(double h, double r1, double r2){

return 3.14159265358979 * h *(pow(r1, 2) - pow(r2, 2));
}





int main(){

double notebook_price;
double notebook_quantity;

double pencil_price;
double pencil_quantity;

std::cout << "Enter data: " << std::endl;
std::cout << "Pencil price > ";
std::cin >> pencil_price;

std::cout << "How many pencils do you want to buy > ";
std::cin >> pencil_quantity;

std::cout << "Notebook price > ";
std::cin >> notebook_price;

std::cout << "How many notebooks do you want to buy > ";
std::cin >> notebook_quantity;

std::cout << "Purchase price: " << pencil_price*pencil_quantity + notebook_price*notebook_quantity << std::endl;


double H, r1, r2;
std::cout << "H = ";
std::cin >> H;

std::cout << "r1 = ";
std::cin >> r1;
std::cout << "r2 = ";
std::cin >> r2;

double result = CylinderVolume(H, r1, r2);

std::cout << "Cylinder volume: " << result;





    return 0;
}