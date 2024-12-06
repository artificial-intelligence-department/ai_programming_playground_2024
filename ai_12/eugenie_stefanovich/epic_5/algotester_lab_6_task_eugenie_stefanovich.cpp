#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


int main(){
    int N , Q , x , y , k;
    string row;
    vector <int> base;
    vector <int> wid;
    vector <int> vert;
    vector <int> gor;
    vector <int> final;
    set<int> razom;
    cin >> N;

    for(int i = N; i > 0; i--)
        wid.push_back(i);

   for(int i = 0; i < N; i++){
    cin >> row;
    for (char c : row) {
        base.push_back(c - 48);

    }
   }
   cout << endl;

    cin >> Q;

    for(int i = 0; i < Q; i++){
        vert.clear();
        gor.clear();
        final.clear();
        razom.clear();
        cin >> x;
        cin >> y;
        if ( base[(((x - 1) * N) + y )-1] != 0){
            cout << 1 << endl << base[((x - 1) * N) + y - 1 ] << endl;
            continue;
            }

        else if ( base[(((x - 1) * N) + y)-1 ] == 0){
            k = y;
            for(int l = 1;k < N ; l++ , k++){
                gor.push_back(base[(((x - 1) * N) + y + l)-1]);
            }
            k = y;
            for(int l = 1;k > 1 ; l++ , k--){
                gor.push_back(base[((x - 1) * N) + y - l - 1]);
            }

            k = x;
            
            for(int l = 1;k < N ; l++ , k++){
                vert.push_back(base[(((x - 1 + l) * N) + y )-1]);
            }

            k = x;

            for(int l = 1;k > 1 ; l++ , k--){
                vert.push_back(base[((x - 1 - l) * N) + y - 1]);
            }


            
            for (int num : gor) {
                razom.insert(num);
             }
            for (int num : vert) {
                razom.insert(num);
            }

            for (int num : wid) {
                if (razom.find(num) == razom.end()) {
                     final.push_back(num); 
                }
            }


            if(final.size() == 0){
                cout << 0 << endl;
                continue;
            }
  
            cout << final.size() << endl;

            sort(final.begin(), final.end());

            for (int num : final) 
                cout << num << " ";
            cout << endl;

        }
       
    }
 
    return 0;
}