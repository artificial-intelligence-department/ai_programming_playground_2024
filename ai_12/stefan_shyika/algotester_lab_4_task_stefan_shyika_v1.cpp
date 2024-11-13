#include <iostream> 
#include <set>

using namespace std;

int main(){
    int N, K;
    set<int> numSet;
    cin >> N >> K;
    int tmp; 

    for(int i = 0; i < N; i++){
        cin >> tmp;
        numSet.insert(tmp);
    }
 
    int len = numSet.size();
    cout << len << endl;

    for(int i = K; i < len + K; i++){
        int index = i % len;
        auto it  = numSet.begin();
        advance(it, index);

        if(i != len + K - 1){
        cout << *it << " ";
        }else{
            cout << *it;
        }
    }
}