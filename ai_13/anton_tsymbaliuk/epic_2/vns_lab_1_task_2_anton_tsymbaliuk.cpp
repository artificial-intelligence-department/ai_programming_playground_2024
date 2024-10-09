#include <iostream>

int main(){
    int n, m;
    while(true){
        std::cout << "Enter n and m: ";
        std::cin >> n >> m;
        std::cout << "Result of n+++m: " << (n+++m) << std::endl;       //результат виразу не буде враховувати додаткову 1, її додавання до n виконається після обрахунку виразу
        std::cout << "Result of m-- >n: " << std::boolalpha << (m-- > n) << std::endl; // віднімання також не врахується під час обчислення, лише після нього й права частина буде вже з доданою одиницею 
        std::cout << "Result of n-- > m: " << std::boolalpha << (n-- >m) << std::endl; //n під час розрахуку буде з додатковою одиницею й лише після розрахунку вона забереться
         }
}