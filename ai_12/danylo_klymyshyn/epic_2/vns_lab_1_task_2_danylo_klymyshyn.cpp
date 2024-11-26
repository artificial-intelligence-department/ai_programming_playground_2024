#include <iostream>




int main(){

int n, m;
std::cout << "n = ";
std::cin >> n;

std::cout << "m = ";
std::cin >> m;

std::cout << "n++ * m = " << (n++*m) << std::endl;
std::cout << "n++ < m = " << (n++<m) << std::endl;
std::cout << "m-- >m = " <<  (m-- >m) << std::endl;




    return 0;
}