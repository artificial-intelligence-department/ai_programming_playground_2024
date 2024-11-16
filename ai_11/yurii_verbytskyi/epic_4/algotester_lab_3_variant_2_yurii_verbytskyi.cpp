#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> universal_set(vector<int>& a, vector<int>& b){
    vector<int> uniq = a; 
    for (int num : b){ 
        if (find(uniq.begin(), uniq.end(), num) == uniq.end()){ 
            uniq.push_back(num);  
            }
        }
             return uniq;
}


int main(){
int N, M; 
cin >> N;

vector<int> a(N);
for(int i = 0; i < N; i++){
    cin >> a[i];
}
cin >> M;
vector<int> b(M);
for(int i = 0; i < M; i++){
    cin >> b[i];
}


int same = 0;
for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
        if(a[i] == b[j]){
            same++;
        }
    }
}


vector<int> uniq = universal_set(a, b); 
int unicquantity = uniq.size();

cout << endl;    
cout << same << endl;
cout << unicquantity << endl;
    return 0;
}
