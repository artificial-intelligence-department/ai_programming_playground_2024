#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N,K; 
    vector<int>::iterator new_end;
    cin >> N >> K;
    vector<int> a(N);
    for(int i=0; i< N; i++){
        cin >> a[i];
    }
    sort(a.begin() , a.begin()+N);
    new_end = unique(a.begin(), a.begin() + N);
    a.resize(distance(a.begin(), new_end));

    rotate(a.begin(), a.begin()+(K%a.size()), a.end());

    cout << a.size();
    cout << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    return 0;
}