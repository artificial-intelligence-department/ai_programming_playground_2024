#include <iostream>

using namespace std;

int main(){
    int nominal [] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int k = 9;
    int result = 0;
    int n;
    cin >> n;

    for (int i = 0; i < k; i++)
    {
        int num_nom = n/ nominal[i];
        result += num_nom;
        n -= num_nom * nominal[i];
    }
    
    cout << result << endl;

    return 0;
}