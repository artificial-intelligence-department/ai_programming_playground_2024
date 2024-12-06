///Перехід дороги
#include <iostream>

int main(){
int n;
std::cin >> n;
int counter = 0;

int *array = new int[n];
for(int i = 0; i < n;++i){
    std::cin >> array[i];
}

for(int i = 0; i < n-1; ++i){
    if((array[i] % 2) != (array[i+1] % 2))
        ++counter;

}


std::cout << counter;
return 0;
}