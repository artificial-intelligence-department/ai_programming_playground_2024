#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    char s[256];

    gets(s);
    // fgets(s, sizeof(s), stdin);
    vector<char> nums;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            nums.push_back(s[i]);
        }
    }
    sort(nums.begin(), nums.end(),greater<int>());

    int indexfornums = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            s[i] = nums[indexfornums++];
        }
    }

    cout << s << endl;

    return 0;
}