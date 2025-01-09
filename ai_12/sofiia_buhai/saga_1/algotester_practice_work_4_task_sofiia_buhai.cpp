#include <iostream>
#include <cmath>

int main() {
    unsigned short n, k;
    std::cin >> n;
    k=sqrt(n);
    char given[k][k];
    std::string s, answer;
    std::cin >> s;
    int count=0;
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            given[i][j] = s[count++];
        }
    }
    for(int l=0; l < 2*k-1; l++){
        for(int i=0; i<k; i++){
            int j=l-i;
            if(j>=0 && j<k){
                answer += given[i][j];
            }
        }
    }
    std::cout << answer;
    return 0;
}

