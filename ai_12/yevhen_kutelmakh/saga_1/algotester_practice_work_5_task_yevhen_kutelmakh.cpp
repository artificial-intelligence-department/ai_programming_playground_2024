#include <iostream>
using namespace std;

int sum(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

int main() {
    int n, k;
    cin >> n>> k;
    int *commands = new int[k];
    for(int i = 0; i < k; i++)
        commands[i] = 1;
    int counter = 0;
    int s = 0;
    while(sum(commands, k) != n) {
        if(counter < k) {
            commands[counter]++;
            counter++;
        } else {
            counter = 0;
            s++;
        }
        if(s==2) {
            cout << "Impossible";
            return 0;
        }
    }
    for(int i = 0; i < k; i++)
        cout << commands[i] << " ";
    return 0;
}
