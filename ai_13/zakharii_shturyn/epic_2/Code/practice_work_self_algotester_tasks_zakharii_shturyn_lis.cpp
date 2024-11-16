#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    short numsnum;
    cin >> numsnum;
    vector<int> LIS(numsnum, 1);
    vector<int> nums(numsnum);

    for(int i = 0; i < numsnum; i++)
        cin >> nums[i];

    for(int i = numsnum - 1; i >= 0; i--) {
        for(int j = i; j < numsnum; j++){
            if(nums[i] < nums[j]) {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
    }
    auto result = max_element(LIS.begin(), LIS.end());
    cout << *result;
    return 0;
}