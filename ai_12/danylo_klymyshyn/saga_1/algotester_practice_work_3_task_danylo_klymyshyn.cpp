///Коля, Вася і Теніс

#include<iostream>




int main(){


int n;
std::cin >>n;

char *array = new char[n];

for(int i = 0; i < n; ++i){
    std::cin >> array[i];
}


int V = 0;
int K = 0;
int win_v = 0;
int win_k = 0;
for(int i = 0; i < n; ++i){
    if(array[i] == 'V')
        ++V;
    if(array[i] == 'K')
        ++K;
    if(V >= 11 && (V - K) >=2){
        ++win_v;
        V = 0;
        K = 0;
    }
    if(K >= 11 && (K-V)>=2){
        ++win_k;
        V = 0;
        K = 0;
    
    }
}


std::cout << win_k << ':' << win_v << std::endl;

if(V !=0 || K != 0)
    std::cout << K << ':' << V;



    return 0;
}