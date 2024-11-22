#include <iostream>
#include <vector>

int main(){

    int n, a1, a2, a3;
    std::cin >> n;
    std::vector<int> r {};
    r.resize(n);
    
    int erase_array[3];
    
    for(int i = 0; i < n; ++i)
        std::cin >> r[i];

    for(int i = 0; i < 3; ++i){
        std::cin >> erase_array[i];
    }
    for(int i = 0; i < r.size(); ++i){
        for(int j = 0; j < 3; ++j){
            if(r[i] == erase_array[j]){
                r.erase(r.begin() + i);
                --i;
            }
        }

    }
    if(r.size() == 0){
        std::cout << '0';
        return 0;
    }
    std::cout << r.size() - 1 << std::endl;
    for(int i = 0; i < r.size() - 1; ++i){
        std::cout << r[i] + r[i+1] << ' ';
    }
    return 0;
}