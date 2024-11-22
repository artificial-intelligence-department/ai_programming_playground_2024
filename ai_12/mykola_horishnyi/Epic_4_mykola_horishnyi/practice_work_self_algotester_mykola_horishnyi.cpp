#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;  

    int numbers[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 }; 
    int count = 0;  

    for (int denom : numbers) {
        count += n / denom; 
        n %= denom;          
    }

    cout << count << endl; 



    return 0;
}














