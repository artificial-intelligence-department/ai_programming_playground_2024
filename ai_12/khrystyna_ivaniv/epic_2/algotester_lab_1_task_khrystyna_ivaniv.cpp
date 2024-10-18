#include <iostream>

int main() {

    long long H, M;
    std::cin >> H;
    std::cin >> M;
    bool res = true;

    for(int i = 0; i < 3; i++) 
    {
        long long h_i, m_i;
        std::cin >> h_i >> m_i;
        
        if (!((h_i != 0 & m_i == 0)||(h_i == 0 & m_i != 0))){
        res = false;
        }
    H-=h_i;
    M-=m_i;
    }
    
    if((H > 0 & M > 0) & res==true)
        std::cout << "YES";
    
    else 
        std::cout << "NO";
    
    

    return 0;
    
    }