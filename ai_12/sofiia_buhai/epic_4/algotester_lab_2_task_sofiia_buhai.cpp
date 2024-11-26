#include <iostream>

int main(){
    unsigned short N, first=0;
    bool collision=0, miss=0, stopped=0;
    std::cin >> N;
    unsigned short a[N], second = N-1;
    for(int i=0; i<N; i++){
        std::cin >> a[i];
    }
    do{
        if((first+1) == second){
            std::cout << first+1 << " " << second+1;
            std::cout<< "\nStopped";
            return 0;
        } else {
            if(first == second){
                std::cout << first+1 << " " << second+1;
                std::cout<< "\nCollision";
                return 0;
            } else {
                if(first > second) {
                    std::cout << first+1 << " " << second+1;
                    std::cout<< "\nMiss";
                    return 0;
                }
            }
        }
        first += a[first];
        second -= a[second];
    } while (collision==0 && miss==0 && stopped==0);
    return 0;
}