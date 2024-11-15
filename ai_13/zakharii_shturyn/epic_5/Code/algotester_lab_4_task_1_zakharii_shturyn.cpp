//дискретка
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void Print(vector<int> res) {
    cout << res.size() << endl;
    for(int elm : res) {
        cout << elm << " ";
    }
    cout << endl << endl;
}

int main() {

    short sizeN, sizeM;
    cin >> sizeN;
    vector<short> N(sizeN);
    for(int i = 0; i < sizeN; i++) {
        cin >> N[i];
    }
    cin >> sizeM;
    vector<short> M(sizeM);
    for(int i = 0; i < sizeM; i++) {
        cin >> M[i];
    }

    unordered_map<int, int> freqN, freqM;
    for (int num : N) freqN[num]++;
    for (int num : M) freqM[num]++;

    vector<int> difference_N_M;
    for (auto& [num, count] : freqN) {
        if (freqM.find(num) == freqM.end()) {   //коли find нічо не знаходить, то воно дорівнює кінцю списка
            difference_N_M.insert(difference_N_M.end(), count, num);
        } else if (freqN[num] > freqM[num]) {
            difference_N_M.insert(difference_N_M.end(), freqN[num] - freqM[num], num);
        }
    }
    sort(difference_N_M.begin(), difference_N_M.end());
    Print(difference_N_M);

    vector<int> difference_M_N;
    for (auto& [num, count] : freqM) {
        if (freqN.find(num) == freqN.end()) {
            difference_M_N.insert(difference_M_N.end(), count, num);
        } else if (freqM[num] > freqN[num]) {
            difference_M_N.insert(difference_M_N.end(), freqM[num] - freqN[num], num);
        }
    }
    sort(difference_M_N.begin(), difference_M_N.end());
    Print(difference_M_N);

    vector<int> intersection;
    for (auto& [num, count] : freqN) {
        if (freqM.find(num) != freqM.end()) {
            int common_count = min(freqN[num], freqM[num]);     //шукаємо мінімум скільки додавати
            intersection.insert(intersection.end(), common_count, num);
        }
    }
    sort(intersection.begin(), intersection.end());
    Print(intersection);

    vector<int> union_res = difference_N_M;
        for(int elm : M) {
            union_res.push_back(elm);
        }
    sort(union_res.begin(), union_res.end());
    Print(union_res);

    vector<int> sym_dif = difference_N_M;
        for(int elm : difference_M_N) {
            sym_dif.push_back(elm);
        }
    sort(sym_dif.begin(), sym_dif.end());
    Print(sym_dif);


    return 0;
}