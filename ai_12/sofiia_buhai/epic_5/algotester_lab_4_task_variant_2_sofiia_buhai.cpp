#include <iostream>
#include <vector>

int main(){
    int N, K;
    std::cin >> N >> K;
    int a[N];
    std::vector<int> answer;
    for(int i=0; i<N; i++){
        std::cin >> a[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(a[j]==a[i] && j!=i){
                for(int k=j; k<N-1; k++){
                    a[k]=a[k+1];
                }
                N--;
                j--;
            }
        }
    }

    for (int startIndex = 0; startIndex < N - 1; ++startIndex){
        int smallestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < N; ++currentIndex){
            if (a[currentIndex] < a[smallestIndex])
                smallestIndex = currentIndex;
        }
        std::swap(a[startIndex], a[smallestIndex]);
    }
    while(K>N){
        K-=N;
    }
    for(int i=K; i<N; i++){
        answer.push_back(a[i]);
    }
    for(int i=0; i<K; i++){
        answer.push_back(a[i]);
    }

    std::cout << answer.size() << "\n";
    for(int i : answer){
        std::cout << i << " ";
    }


    return 0;
}