#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line; 
    vector<vector<int>> grid(n); 

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < n; j++) {
            grid[i].push_back(line[j] - '0');
        }
    }

    int tap; 
    cin >> tap;

    vector<int> nums(n), res;
    for (int qi = 0; qi < tap; qi++) {
        iota(nums.begin(), nums.end(), 1); 
        int cnt = 0; 
        res.clear();

        int r, c;
        cin >> r >> c;

        if (grid[r - 1][c - 1] != 0) {
            cout << 1 << endl;
            cout << grid[r - 1][c - 1];
        } else {
            for (int j = 0; j < n; j++) {
                if (grid[r - 1][j] != 0) {
                    nums[grid[r - 1][j] - 1] = 0;
                }
                if (grid[j][c - 1] != 0) {
                    nums[grid[j][c - 1] - 1] = 0;
                }
            }

            for (int num : nums) {
                if (num != 0) {
                    cnt++;
                    res.push_back(num);
                }
            }

            cout << cnt << endl;
            for (int num : res) {
                cout << num << ' ';
            }
        }
        cout << endl << endl;
    }

    return 0;
}
