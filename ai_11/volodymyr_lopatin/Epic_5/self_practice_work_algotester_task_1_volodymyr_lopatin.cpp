#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isValidGenome(const string& genome) {
    if (genome.empty() || genome.size() > 30) {
        return false;
    }
    for (char c : genome) {
        if (c != 'C' && c != 'G' && c != 'U' && c != 'A') {
            return false;
        }
    }
    return true;
}

string findOriginalGenome(const string& genome1, const string& genome2) {
    int n = genome1.size(), m = genome2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (genome1[i - 1] == genome2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (genome1[i - 1] == genome2[j - 1]) {
            lcs += genome1[i - 1];
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    
    reverse(lcs.begin(), lcs.end());
    return lcs.empty() ? "No original genome" : lcs;
}

int main() {
    string genome1, genome2;
    cin >> genome1 >> genome2;

    if (!isValidGenome(genome1) || !isValidGenome(genome2)) {
        return 0;
    }

    cout << findOriginalGenome(genome1, genome2) << endl;
    return 0;
}
