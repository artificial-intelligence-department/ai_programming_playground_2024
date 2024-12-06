#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void printVector(vector<int>& vec) 
{
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    int N, K;
    cin >> N;
    if (N < 1 || N > 1000) return 1;

    cin >> K;
    if (K < 1 || K > 1000) return 1;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        if (numbers[i] < 0 || numbers[i] > 100) return 1;
    }

    set<int> uniqueSet;
    for (int i = 0; i < N; i++) {
        uniqueSet.insert(numbers[i]);
    }

    vector<int> uniqueNumbers;
    for (int val : uniqueSet) {
        uniqueNumbers.push_back(val);
    }

    sort(uniqueNumbers.begin(), uniqueNumbers.end());

    K = K % uniqueNumbers.size();
    vector<int> rotatedNumbers;
    for (int i = K; i < uniqueNumbers.size(); i++) {
        rotatedNumbers.push_back(uniqueNumbers[i]);
    }
    for (int i = 0; i < K; i++) {
        rotatedNumbers.push_back(uniqueNumbers[i]);
    }

    printVector(rotatedNumbers);

    return 0;
}

