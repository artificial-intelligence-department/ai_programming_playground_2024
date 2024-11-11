#include <iostream>
using namespace std;

struct Petryk {
    int start;
    int end;
};

int main() {
    int n;
    cin >> n;

    int numbers[100];  
    Petryk segments[100];
    int numCount = 0;
    int segCount = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;

        if (cin.peek() == '\n') {
            numbers[numCount++] = a; 
        } else {
            cin >> b;
            segments[segCount++] = {a, b};
        }
    }

    for (int i = 0; i < segCount; i++) {
        int count = 0;
        for (int j = 0; j < numCount; j++) {
            if (numbers[j] > segments[i].start && numbers[j] < segments[i].end) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
