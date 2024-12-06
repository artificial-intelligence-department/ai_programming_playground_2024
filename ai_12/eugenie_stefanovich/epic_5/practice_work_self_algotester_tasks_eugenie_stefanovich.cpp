#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

int main() {
    int N;
    double b, k;

    priority_queue<double, vector<double>, greater<double>> pq; 

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> b;
        pq.push(b); 
    }

    while (pq.size() > 1) {
        
        double first = pq.top(); pq.pop();
        double second = pq.top(); pq.pop();

        
        k = (first + second) / 2.0;
        pq.push(k);
    }

   
    cout << fixed  << pq.top() << endl;
    return 0;
}

