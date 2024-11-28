#include <iostream>
#include <vector>
using namespace std;
// 1 - ascending order 0 - descending order
vector<int> insertion_sort(vector<int> a, bool ascending){
    int temp;
    vector<int>::iterator start = a.begin(), end = a.end(), insert;
    for(vector<int>::iterator first = start; first < end; first++){
        for(vector<int>::iterator second = first; second >= start; second--){
            if(ascending){
                if(*second >= *first){
                    insert = second;
                }
            }
            else{
                if(*second <= *first){
                    insert = second;
                }
            }

        }
        temp = *first;
        a.erase(first);
        a.insert(insert, temp);
    }
    return a;
}
int main(){
    int N, x;
    vector <int> a, a1, a2, a3;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> x;
        a.push_back(x);
    }

    for(int i:a){
        if(i%3 == 0){
            a1.push_back(i);
        }
        else if(i%3 == 1){
            a2.push_back(i);
        }
        else{
            a3.push_back(i);
        }
    }
    a1 = insertion_sort(a1, true);
    a2 = insertion_sort(a2, false);
    a3 = insertion_sort(a3, true);
    a.clear();
    a.insert(a.end(), a1.begin(), a1.end());
    a.insert(a.end(), a2.begin(), a2.end());
    a.insert(a.end(), a3.begin(), a3.end());

    int temp;
    vector<int>::iterator start = a.begin(), end = a.end(), insert;
    for(vector<int>::iterator first = start + 1; first < end; first++){
        for(vector<int>::iterator second = first - 1; second >= start; second--){
            if(*second == *first){
                a.erase(first--);
                end--;
                break;
            } 
        }
    }  
    cout << a.size() << endl;
    for(int i : a){
        cout <<  i << ' ';
    }
    return 0;
}