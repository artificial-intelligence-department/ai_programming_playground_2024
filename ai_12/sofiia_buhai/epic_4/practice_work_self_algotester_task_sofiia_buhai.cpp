#include <iostream>

int main() {
    int N, M, same=0, diff;
    std::cin >> N;
    int a[N];
    for(int i=0; i<N; i++){
        std::cin >> a[i];
    }
    std::cin >> M;
    int b[M];
    for(int i=0; i<M; i++){
        std::cin >> b[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(a[i]==b[j]){
                same++;
            }
        }
    }

    std::cout << same;
    diff = N+M-same;
    std::cout << "\n" << diff;
    return 0;
}