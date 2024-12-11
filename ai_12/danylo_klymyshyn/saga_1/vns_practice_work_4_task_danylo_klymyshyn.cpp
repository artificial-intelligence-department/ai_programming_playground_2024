#include <iostream>
#include <random>


int main(){

std::random_device rd; 
std::mt19937 mersenne(rd());

int ar1[10], ar2[10], ar3[10];
int S_1 = 0, S_2 = 0, S_3 = 0;

for(int i = 0; i < 10; ++i){
    ar1[i] = mersenne() % 11;
    ar2[i] = mersenne() % 11;
    ar3[i] = mersenne() % 11;
}

std::cout << "AR_1 : ";
for(int i = 0; i < 10; ++i){
    std::cout << ar1[i] << ' '; 
    S_1+= ar1[i];   
}

std::cout << "\nAR_2 : ";
for(int i = 0; i < 10; ++i){
    std::cout << ar2[i] << ' ';    
    S_2+= ar2[i];   
}


std::cout << "\nAR_3 : ";
for(int i = 0; i < 10; ++i){
    std::cout << ar3[i] << ' ';    
    S_3+= ar3[i];   
}


std::cout << "\nSA_1: " << S_1/10.0 << "\nSA_2: " << S_2/10.0 << "\nSA_3: " << S_3/10.0;


    return 0;
}