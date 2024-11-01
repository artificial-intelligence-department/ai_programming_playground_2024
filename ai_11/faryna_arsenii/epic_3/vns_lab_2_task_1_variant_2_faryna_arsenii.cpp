#include <iostream>

using namespace std;

int main(){
    
    int sum;
    for (int i = 0; i < 100; i++){
        if (i % 2 == 0){
            sum += i;
        }
    }
    
    cout << "Sum of paired number is: " << sum << endl;
    
    return 0;
}