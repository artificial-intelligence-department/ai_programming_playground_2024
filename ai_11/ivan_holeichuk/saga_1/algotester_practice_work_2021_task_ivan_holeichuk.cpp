#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    int a, b, c;
    cin >> a >> b >> c;

 
    int min_consumption = min({ a + b, a + c, b + c });

    cout << min_consumption << endl;
    return 0;
}

