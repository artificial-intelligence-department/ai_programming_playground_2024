#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    std::stack<int> open_parens;
    std::vector<std::pair<int, int>> pairs;  

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            open_parens.push(i);  
        } else if (s[i] == ')') {
            int open_pos = open_parens.top();
            open_parens.pop();
            pairs.push_back({open_pos + 1, i + 1}); 
        }
    }

    // std::reverse(pairs.begin(), pairs.end());

    std::cout << pairs.size() << "\n";  
    for (const auto &p : pairs) {
        std::cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
