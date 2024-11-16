#include <iostream> 
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;
    int count = 0;

    for (char lucky : x) {
        switch (lucky) {
            case '4':
            case '7':
                count++;
                break;
        }
    }

    cout << count << endl;
    
    return 0;
}
