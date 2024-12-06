#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string d;
    cin >> d;
    int n;
    cin >> n;

    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    unordered_map<string, int> day_index;
    for (int i = 0; i < 7; i++) {
        day_index[days[i]] = i;
    }

    int start_day = day_index[d];

    int full_weeks = n / 7;
    int remaining_days = n % 7;

    vector<int> counts(7, full_weeks);

    for (int i = 0; i < remaining_days; i++) {
        counts[(start_day + i) % 7]++;
    }

    for (int count : counts) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
