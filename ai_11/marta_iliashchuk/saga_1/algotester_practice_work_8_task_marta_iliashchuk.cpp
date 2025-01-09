#include <iostream>
using namespace std;

int main (){
    int N;
    int count = 0;
    string sentence;
    string z = "#";

    cin>>N;
    
    for(int i= 0; i<=N; i++){
        getline(cin, sentence);
        for(int j = 0; j< sentence.size(); j++){
            if(sentence[j] == z[0]){
                count ++;
            }
        }
        for(int j = 0; j< sentence.size(); j++){
            if(sentence[j] == z[0] and sentence[j+1] == z[0]){
                count --;
            }
        }
    }

    cout<<count;
    
    return 0;
}