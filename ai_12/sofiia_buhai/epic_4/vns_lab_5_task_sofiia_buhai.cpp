#include <iostream>

bool can(int ** arr, int n, int m){
    int collumn=1, sum1=0, sum2=0;
    for( ; collumn<(m-1); collumn++){
        for(int i=0; i<n; i++){
            for(int j=0; j<collumn; j++){
                sum1+=arr[i][j];
            }
            for(int j=(collumn+1); j<m; j++){
                sum2 += arr[i][j];
            }
        }
        if(sum1>sum2){
            return 1;
        }
    }
    return 0;
}

int main(){
    int n, m;
    std::cout << "Введіть, будь ласка, кількість рядків : ";
    std::cin >> n;
    int ** arr = new int*[n];
    std::cout << "\nВведіть, будь ласка, кількість стовпців : ";
    std::cin >> m;
    for (int i=0; i<n; i++){
        arr[i]= new int[m];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            std::cin >> arr[i][j];
        }
    }
    if(can(arr, n, m))
        std::cout << "Можна";
    else 
        std::cout << "Ні";
    return 0;
}