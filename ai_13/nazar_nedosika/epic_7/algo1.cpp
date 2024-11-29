#include <iostream>
#include <vector>
using namespace std;

int main() {
    int students, squads;
    cin >> students;
    cin >> squads;

    vector<int> groups(students,1);

    if(students >= squads && students <= squads * 3){ 
        for(int i = groups.size() - 1; i >= 0; i--) {
            for(int j = groups.size() - 1; j > i; j--){

                int a = groups[i];
                int b = groups[j];

                if(a + b <= 3 && groups.size() != squads){ 
                    groups[i] = a + b;
                    groups.erase(groups.begin() + j);
                } 
                else if(groups.size() == squads){
                    break;
                }
            }
        }
        for(int sc : groups){
            cout << sc << " ";
        }
    } 
    else{
        cout << "Impossible";
    }
    return 0;
}