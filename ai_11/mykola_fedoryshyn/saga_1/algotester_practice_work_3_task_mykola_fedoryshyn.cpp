#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int size;
    std::cin >> size;
    int list[size];

    
    for(int i = 0; i < size; i++){
        std::cin >> list[i];
    }


    for(int i = 0; i < (size-1); i++){
        if(abs(list[i]-list[i+1]) < 2){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

}
