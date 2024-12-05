#include <iostream>

int main(){
    unsigned long int l, w, u, d;
    std::cin >> l >> w >> u >> d;
    std::string yes = "Three times Sex on the Beach, please!", 
    no = "Forget about the cocktails, man!";
    if(l<=w && l<=(u+d)){
        std::cout << yes;
    } else {
        std::cout << no;
    }
    return 0;
}