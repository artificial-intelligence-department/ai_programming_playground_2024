#include <iostream>

int main(){
    long long H, M;
    std::cin >> H >> M;
    int i = 3;
    while(i > 0 && H > 0 && M > 0){
        long long h, m;
        std::cin >> h >> m;
        if(h > 0 && m > 0) {
            std::cout << "NO\n";
            return 0;
        }
        H -= h;
        M -= m;
        if(H < 1 || M < 1){
            std::cout << "NO\n";
            return 0;
        }
        i--;
    }
    std::cout << "YES";
    return 0;
}