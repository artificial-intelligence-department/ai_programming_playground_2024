#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N , wid ;
    vector <int> base0;
    vector <int> base1;
    vector <int> base2;
    cin >> N;

    for(int i = 0; i < N ; i++){
        cin >> wid;
        if(wid%3 == 0 )
            base0.push_back(wid);
        else if(wid%3 == 1 || wid%3 == -1 )
            base1.push_back(wid); 
        else if(wid%3 == 2 || wid%3 == -2)
            base2.push_back(wid);
    }

    sort(base0.begin(), base0.end());
    sort(base1.begin(), base1.end());
    reverse(base1.begin(),base1.end());
    sort(base2.begin(), base2.end());
    
   if (base0.size() > 1) {
        for (int i = 0; i < base0.size() - 1; ) {
            if (base0[i] == base0[i + 1]) {
                int k = 1;
                while (i + k < base0.size() && base0[i] == base0[i + k]) {
                    k++;
                }
                base0.erase(base0.begin() + i + 1, base0.begin() + i + k);
            } else {
                i++;
            }
        }
    }

    if (base1.size() > 1) {
        for (int i = 0; i < base1.size() - 1; ) {
            if (base1[i] == base1[i + 1]) {
                int k = 1;
                while (i + k < base1.size() && base1[i] == base1[i + k]) {
                    k++;
                }
                base1.erase(base1.begin() + i + 1, base1.begin() + i + k);
            } else {
                i++;
            }
        }
    }

    if (base2.size() > 1) {
        for (int i = 0; i < base2.size() - 1; ) {
            if (base2[i] == base2[i + 1]) {
                int k = 1;
                while (i + k < base2.size() && base2[i] == base2[i + k]) {
                    k++;
                }
                base2.erase(base2.begin() + i + 1, base2.begin() + i + k);
            } else {
                i++;
            }
        }
    }

    cout << base0.size() + base1.size() + base2.size()  << endl;
    
    for (int num : base0) {
        cout << num << " ";
    }

    for (int num : base1) {
        cout << num << " ";
    }

    for (int num : base2) {
        cout << num << " ";
    }


    return 0;
}