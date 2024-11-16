#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N < 1 || N > 100000){
        cout << "Error" << endl;
        return 1;
    }
    
    vector<char> strings(N);
    for(int i = 0; i < N; ++i){
        cin >> strings[i];
    }

    int count_K = 0, count_V = 0;
    int count_K_score = 0, count_V_score = 0;

    for(int i = 0; i < N; ++i){
        if (strings[i] == 'K'){ 
            count_K++; 
        } else if (strings[i] == 'V'){ 
            count_V++; 
        }

        if ((count_K >= 11 || count_V >= 11) && abs(count_K - count_V) >= 2) {
            if (count_K > count_V) {
                count_K_score++;
            } else {
                count_V_score++;
            }
            count_K = 0;
            count_V = 0;
        }
    }
    cout << count_K_score << ":" << count_V_score << endl;

    if (count_K > 0 || count_V > 0){
        cout << count_K << ":" << count_V;
    } 
    return 0;
}