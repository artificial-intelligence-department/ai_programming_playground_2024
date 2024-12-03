#include <vector>
#include <iostream>
using namespace std;

void prime(vector<int> &arr, int number) {
    if(number==0) return;
    else {
        if(number >= 4 || number == 2) {
            number -= 2;
            arr.push_back(2);
        } else {
            number -= 3;
            arr.push_back(3);
        }
        prime(arr, number);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    prime(nums, n);
    cout << nums.size() << "\n";
    for(int el : nums)
        cout << el << " ";
    return 0;
}
