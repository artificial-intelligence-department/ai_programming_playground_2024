#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;
    int count = 0;

    for (char lucky : x) {
        if (lucky == '4' || lucky == '7') {
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}
