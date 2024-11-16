#include <iostream>
using namespace std;

int countChar(const string& str, char ch){
    int count = 0; 
    bool counted = false;
    for (char c : str){
        if(c==ch){
            if (!counted){
            count++;
            counted = true;
            }
        }
        else counted = false;
    }
  
    return count;
}

int main(){
    int N, result = 0;
    string str;
    char target = '#';
    cin >> N;
    cin.ignore();

    string *array = new string[N];
    for(int i=0; i<N; i++){
        getline(cin, str);
        array[i] = str;
    }

    for(int i=0; i<N; i++){
        result += countChar(array[i], target);
    }

    cout << result;
    delete[] array;
    return 0;
}

