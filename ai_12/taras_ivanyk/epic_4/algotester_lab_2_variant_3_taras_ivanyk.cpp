#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i]; 
    }
    int first = 0;
    int last = N-1;
    
    while(true){
        if(first == last - 1){
            cout << first + 1 << " " << last + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }
        if(first == last){
            cout << first + 1 << " " << last + 1 << endl;
            cout << "Collision" << endl;
            break;
        }

        int next_first = first + arr[first];
        int next_last = last - arr[last];

        first = next_first;
        last = next_last;

        if(first > last){
            cout << first + 1 << " " << last + 1 << endl;
            cout << "Miss" << endl;
            break;
        } 

        if(first == last - 1){
            cout << first + 1 << " " << last + 1 << endl;
            cout << "Stopped" << endl;
            break;
        }
        if(first == last){
            cout << first + 1 << " " << last + 1 << endl;
            cout << "Collision" << endl;
            break;
        }
    }
    return 0;
}
   