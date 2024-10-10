#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long total_cookies = 0; 
    int cookies_in_pack;

    while (n--) {
        cin >> cookies_in_pack;
        total_cookies += cookies_in_pack - 1; 
    }

    cout << total_cookies << endl;
    return 0;
}
