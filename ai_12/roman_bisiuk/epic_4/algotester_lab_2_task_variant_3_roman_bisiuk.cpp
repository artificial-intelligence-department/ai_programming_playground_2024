#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    size_t size;
    cin >> size;

    vector<int> arr(size);
    for (size_t i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int leftP = 0;          
    int rightP = size - 1;     
    string answer = "Miss"; 
    bool canMove = true;

    while (canMove) {
        if (leftP == rightP) {
            answer = "Collision";
            break;
        }
        if (leftP == rightP - 1) {
            answer = "Stopped";
            break;
        }

        leftP += arr[leftP];
        rightP -= arr[rightP];

        if (leftP > rightP) {
            answer = "Miss";
            break;
        }
    }

    cout << leftP + 1 << ' ' << rightP + 1 << '\n' << answer;
    return 0;
}
