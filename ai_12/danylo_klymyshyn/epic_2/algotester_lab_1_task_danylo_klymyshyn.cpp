#include <iostream>

int main(){

long long H, M, hi, mi;
bool check = false;

std::cin >> H >> M;

for(int i = 0; i < 3; ++i){
    std::cin >> hi >> mi;
    if(hi != 0 && mi !=0)
        check = true;
    H-= hi;
    M-=mi;
}

if(H > 0 && M > 0 && check == false)
    std::cout << "YES";
else
    std::cout << "NO";
    return 0;
}