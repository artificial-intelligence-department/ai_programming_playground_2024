#include <iostream>

using namespace std;

int main(){
    int nominal[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int price;
    
    cin >> price;
    
    int num = 0;
    
    for (int i = 8; i > -1; i--){
        while(nominal[i] <= price){
            price -= nominal[i];
            num++;
        }
        if (price == 0){
            break;
        }
    }
    
    cout << num;
    return 0;
}