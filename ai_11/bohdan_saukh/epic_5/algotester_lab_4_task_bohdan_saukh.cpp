#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int mas[n];
    vector<int> mas_0;
    vector<int> mas_1;
    vector<int> mas_2;

    for (int i = 0; i < n; i++){
        cin >> mas[i];
        if (mas[i] % 3 == 0){
            mas_0.push_back(mas[i]);
        }
        if (mas[i] % 3 == 1){
            mas_1.push_back(mas[i]);
        }
        if (mas[i] % 3 == 2){
            mas_2.push_back(mas[i]);
        }
    }
    
    
    sort(mas_2.begin(), mas_2.end());
    auto it = unique(mas_2.begin(), mas_2.end());
    mas_2.erase(it, mas_2.end());
    
    sort(mas_1.begin(), mas_1.end(), greater<int>());
    auto it_1 = unique(mas_1.begin(), mas_1.end());
    mas_1.erase(it_1, mas_1.end());
    
    sort(mas_0.begin(), mas_0.end());
    auto it_0 = unique(mas_0.begin(), mas_0.end());
    mas_0.erase(it_0, mas_0.end());
    
    cout << mas_0.size() + mas_1.size() + mas_2.size() << endl;

    for (int i = 0; i < mas_0.size(); i++){
        cout << mas_0[i] << " ";
    }
    for (int i = 0; i < mas_1.size(); i++){
        cout << mas_1[i] << " ";
    }
    for (int i = 0; i < mas_2.size(); i++){
        cout << mas_2[i] << " ";
    }

    return 0;
}
   
