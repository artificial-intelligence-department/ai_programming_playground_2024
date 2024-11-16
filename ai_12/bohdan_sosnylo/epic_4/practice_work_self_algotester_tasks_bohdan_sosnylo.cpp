#include <iostream>
#include <algorithm>

using namespace std;

struct TicketManager {
    int prices[10]; 
    int n;         
    int k;         
    int z;         

    void read() {
        cin >> n >> k >> z;
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
    }

    int maxG() {
        sort(prices, prices + n);  
        int girls_count = 0;      
        int total_cost = 0;     

        for (int i = 0; i < n; i++) {
            if (total_cost + 2*prices[i] > z) {
                break;  
            }
            total_cost += 2*prices[i];
            girls_count++;
            if (girls_count == k) {
                break;  
            }
        }

        return girls_count;
    }
};

int main() {
    TicketManager tm;
    tm.read();
    cout << tm.maxG() << endl;
    return 0;
}
