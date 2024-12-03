#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long initial_hours, initial_minutes;
    cin >> initial_hours >> initial_minutes;

    bool valid = true;

    for (int j = 0; j < 3; ++j) {
        long long hours_spent, minutes_spent;
        cin >> hours_spent >> minutes_spent;

        if (hours_spent != 0 && minutes_spent != 0) {
            valid = false;
            break;
        }

        initial_hours -= hours_spent;
        initial_minutes -= minutes_spent;
    }

    if (valid && initial_hours > 0 && initial_minutes > 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
