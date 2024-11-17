#include <iostream>
#include <string>

using namespace std;

int main() {
    string week_days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    string start_day;
    int n;
    
    cin >> start_day >> n;
    
    int start_index = 0;
    for (int i = 0; i < 7; i++) {
        if (week_days[i] == start_day) {
            start_index = i;
            break;
        }
    }
    
    int base_count = n / 7;
    int remainder = n % 7;
    
    int days_count[7] = {base_count, base_count, base_count, base_count, base_count, base_count, base_count};
    
    for (int i = 0; i < remainder; i++) {
        days_count[(start_index + i) % 7]++;
    }
    

    for (int i = 0; i < 7; ++i) {
        cout << days_count[i] << " ";
    }
    cout << endl;
    
    return 0;
}
