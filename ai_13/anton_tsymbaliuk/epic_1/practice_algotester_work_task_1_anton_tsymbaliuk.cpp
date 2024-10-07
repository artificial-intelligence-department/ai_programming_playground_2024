#include <iostream>

int main(){
    int n, m;
    std::cin >> n >> m;
    int* arr = new int[n + 1];              //n+1 бо алготестер починає не з 0, а з 1
    int* sums = new int[n + 1];
    sums[0] = 0;
    for(int i = 1; i <= n; i++){
        std::cin >> arr[i];
        sums[i] = sums[i - 1] + arr[i];
    }
    int type, l, r, i, d;
    int* sum = new int[m];
    int count = 0;
    for(int j = 0; j < m; j++){
        std::cin >> type;
        if(type == 1){
            std::cin>>l >> r;
            sum[count] = sums[r] - sums[l - 1];
            count++;
        }
        else{
            std::cin>>i >> d;
            for(int b = i; b <= n; b++) sums[b] += d;
            arr[i] += d;
        }
        
        
    }
    for(int b = 0; b < count; b++)std::cout << sum[b] << std::endl;
    delete[] arr;
    delete[] sums;
    delete[] sum;
    return 0;
}