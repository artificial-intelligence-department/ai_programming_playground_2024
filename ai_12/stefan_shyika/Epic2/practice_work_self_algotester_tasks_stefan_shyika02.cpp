#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void generateSubsetSums(const vector<long long>& arr, int index, long long currentSum, set<long long>& sums, long long c) {
    // If the sum exceeds c stop
    if (currentSum > c) return;

    // If we've reached the end of the array, add the sum to the set
    if (index == arr.size()) {
        sums.insert(currentSum);
        return;
    }
    
    // Case 1: Exclude the current element and move to the next
    generateSubsetSums(arr, index + 1, currentSum, sums, c);
    
    // Case 2: Include the current element and move to the next
    generateSubsetSums(arr, index + 1, currentSum + arr[index], sums, c);
}

int main() {
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<long long> left(p.begin(), p.begin() + n / 2);
    vector<long long> right(p.begin() + n / 2, p.end());

    set<long long> leftSums, rightSums;
    generateSubsetSums(left, 0, 0, leftSums, c);
    generateSubsetSums(right, 0, 0, rightSums, c);

    // Convert the rightSums set to a sorted vector for binary search
    vector<long long> rightSumsVec(rightSums.begin(), rightSums.end());
    sort(rightSumsVec.begin(), rightSumsVec.end());

    int result = 0;
    for (long long sum : leftSums) {
        if (sum <= c) {
            // Find how many sums in rightSums can be paired with this sum
            result += upper_bound(rightSumsVec.begin(), rightSumsVec.end(), c - sum) - rightSumsVec.begin();
        }
    }

    //sum == 0 is included by default, subtract 1 if leftSums contains 0
    if (leftSums.count(0) > 0) {
        result--;
    }

    cout << result;
}

