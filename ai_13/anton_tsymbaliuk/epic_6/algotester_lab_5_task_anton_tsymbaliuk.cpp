#include <iostream>
#include <vector>


int main(){
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> vec(N);
    for(int i = 0; i < N; i++){
        std::cin >> vec[i];
    }
    for(int i = N - 2; i >= 0; i--){
        for(int j = 0; j < M; j++){
            if(vec[i][j] == 'S') {
                int ptr = i;
                for(int k = i + 1; k < N; k++){
                    if(vec[k][j] == 'O') ptr = k;
                    else break;
                }
                std::swap(vec[i][j], vec[ptr][j]);
            }
        }
    }
    std::cout << std::endl;
    for(std::string str : vec) std::cout << str << std::endl;
    return 0;
}