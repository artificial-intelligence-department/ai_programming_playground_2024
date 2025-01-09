#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nominal = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    
    int count = 0;

    for (int  a : nominal) {
        count += n /  a;
        n %=  a;
    }

    cout << count << endl;
    return 0;
}