#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> kupiurs = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    long long a;
    long long result = 0;
    cin >> a;
    for (int i = 0; i < kupiurs.size(); i++) {
        result += a / kupiurs[i];
        a %= kupiurs[i];
    }
    cout << result << endl;
    return 0;
}
