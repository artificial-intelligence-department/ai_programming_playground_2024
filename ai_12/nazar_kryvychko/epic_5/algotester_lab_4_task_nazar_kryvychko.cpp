#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to print the size and sorted elements of a vector
void printSetResult(const vector<int>& result) {
    cout << result.size() << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to perform the set operations
void manualSetOperations() {
    int N, M;
    
    // Input for the first array
    cin >> N;
    vector<int> array1(N);
    for (int i = 0; i < N; ++i) {
        cin >> array1[i];
    }

    // Input for the second array
    cin >> M;
    vector<int> array2(M);
    for (int i = 0; i < M; ++i) {
        cin >> array2[i];
    }

    // Use unordered_map to count occurrences of each element
    unordered_map<int, int> count1, count2;
    for (int num : array1) {
        count1[num]++;
    }
    for (int num : array2) {
        count2[num]++;
    }

    // Calculate difference N - M
    vector<int> difference_N_M;
    for (const auto& pair : count1) {
        int num = pair.first;
        int count = pair.second;
        if (count2.find(num) == count2.end()) {
            difference_N_M.insert(difference_N_M.end(), count, num);
        } else {
            // If it exists in both, add the difference in counts
            int diffCount = count - count2[num];
            if (diffCount > 0) {
                difference_N_M.insert(difference_N_M.end(), diffCount, num);
            }
        }
    }
    
    // Calculate difference M - N
    vector<int> difference_M_N;
    for (const auto& pair : count2) {
        int num = pair.first;
        int count = pair.second;
        if (count1.find(num) == count1.end()) {
            difference_M_N.insert(difference_M_N.end(), count, num);
        } else {
            // If it exists in both, add the difference in counts
            int diffCount = count - count1[num];
            if (diffCount > 0) {
                difference_M_N.insert(difference_M_N.end(), diffCount, num);
            }
        }
    }

    // Calculate intersection
    vector<int> intersection;
    for (const auto& pair : count1) {
        int num = pair.first;
        if (count2.find(num) != count2.end()) {
            int minCount = min(pair.second, count2[num]);
            intersection.insert(intersection.end(), minCount, num);
        }
    }

    // Calculate union
    vector<int> unionSet;
    for (const auto& pair : count1) {
        int num = pair.first;
        int count = pair.second;
        unionSet.insert(unionSet.end(), count, num);
    }
    for (const auto& pair : count2) {
        int num = pair.first;
        int count = pair.second;
        if (count1.find(num) == count1.end()) {
            unionSet.insert(unionSet.end(), count, num);
        }
    }

    // Calculate symmetric difference
    vector<int> symmetric_difference;
    for (const auto& pair : count1) {
        int num = pair.first;
        if (count2.find(num) == count2.end()) {
            symmetric_difference.insert(symmetric_difference.end(), pair.second, num);
        } else {
            int diffCount = pair.second - count2[num];
            if (diffCount > 0) {
                symmetric_difference.insert(symmetric_difference.end(), diffCount, num);
            }
        }
    }
    for (const auto& pair : count2) {
        int num = pair.first;
        if (count1.find(num) == count1.end()) {
            symmetric_difference.insert(symmetric_difference.end(), pair.second, num);
        } else {
            int diffCount = pair.second - count1[num];
            if (diffCount > 0) {
                symmetric_difference.insert(symmetric_difference.end(), diffCount, num);
            }
        }
    }

    // Sort results for output
    sort(difference_N_M.begin(), difference_N_M.end());
    sort(difference_M_N.begin(), difference_M_N.end());
    sort(intersection.begin(), intersection.end());
    sort(unionSet.begin(), unionSet.end());
    sort(symmetric_difference.begin(), symmetric_difference.end());

    // Print results
    printSetResult(difference_N_M);
    printSetResult(difference_M_N);
    printSetResult(intersection);
    printSetResult(unionSet);
    printSetResult(symmetric_difference);
}

int main() {
    manualSetOperations();
    return 0;
}