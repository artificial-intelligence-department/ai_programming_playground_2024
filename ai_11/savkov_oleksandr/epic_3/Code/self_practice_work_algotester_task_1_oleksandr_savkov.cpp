#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> votes(n);
    long long sum_votes = 0;

    for (int i = 0; i < n; i++) {
        cin >> votes[i];
        sum_votes += votes[i];
    }

    int gcd_votes = votes[0];
    for (int i = 1; i < n; i++) {
        gcd_votes = gcd(gcd_votes, votes[i]);
    }

    long long result = sum_votes / gcd_votes;
    cout << result << endl;

    return 0;
}
