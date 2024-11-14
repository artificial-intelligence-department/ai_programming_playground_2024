#include <iostream>
#include <vector>           
#include <algorithm>
#include <set>

using namespace std;

int main (){

    int N;                                                 
    int M;
    vector <int> Vector1, Vector2;   

    cin >> N;
    for (int i = 0; i < N; i++){                        
        int Number;
        cin >> Number;
        Vector1.push_back(Number); 
    }

    cin >> M;

    for (int i = 0; i < M; i++){
        int Number;
        cin >> Number;
        Vector2.push_back(Number); 
    }

    int common = 0;
    int unique = 0;

    bool isCommon = false; 
    for (int i = 0; i < Vector1.size(); i++) {
        for (int j = 0; j < Vector2.size(); j++) {
            if (Vector1[i] == Vector2[j]) {
                common++; 
                break; 
            }
        }
    }

    unique = (Vector1.size() + Vector2.size()) - common;
        
    cout << common << endl;
    cout << unique << endl;

    return 0;
} 