#include <iostream>
#include <vector>

int main(){
    int size;
    std::cin >> size;
    std::vector<int> vec(size);
    for(int i = 0; i < size; i++) std::cin >> vec[i];
    int p1 = 1;
    int p2 = size;
    int i = 0;
    int j = size - 1;
    while(i != j && i < j && j != i + 1){
        p1 += vec[i];
        i += vec[i];
        p2 -= vec[j];
        j -= vec[j];
    }
    if(i == j) std::cout << p1 << " " << p2 << "\nCollision";
    else if(j == i + 1) std::cout << p1 << " " << p2 << "\nStopped";
    else std::cout << p1 << " " << p2 << "\nMiss";
    return 0;
}