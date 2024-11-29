#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printResult(const vector<int>& res) {
    cout << res.size() << endl;
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl << endl;
}

void vidn(const vector<int>& mas1, const vector<int>& mas2) {
    vector<int> res;
    vector<int> sm1 = mas1;
    vector<int> sm2 = mas2;
    
    sort(sm1.begin(), sm1.end());
    sort(sm2.begin(), sm2.end());

    int i = 0, j = 0;
    while (i < sm1.size() && j < sm2.size()) {
        if (sm1[i] < sm2[j]) {
            res.push_back(sm1[i]); 
            i++;
        } else if (sm1[i] > sm2[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < sm1.size()) {
        res.push_back(sm1[i++]);
    }

    printResult(res);
}

void per(const vector<int>& mas1, const vector<int>& mas2) {
    vector<int> res;
    vector<int> sm1 = mas1;
    vector<int> sm2 = mas2;
    
    sort(sm1.begin(), sm1.end());
    sort(sm2.begin(), sm2.end());

    int i = 0, j = 0;
    while (i < sm1.size() && j < sm2.size()) {
        if (sm1[i] < sm2[j]) {
            i++;
        } else if (sm1[i] > sm2[j]) {
            j++;
        } else {
            res.push_back(sm1[i]);
            i++;
            j++;
        }
    }

    printResult(res);
}

void obj(const vector<int>& mas1, const vector<int>& mas2) {
    vector<int> res;
    vector<int> sm1 = mas1;
    vector<int> sm2 = mas2;
    
    sort(sm1.begin(), sm1.end());
    sort(sm2.begin(), sm2.end());

    int i = 0, j = 0;
    while (i < sm1.size() && j < sm2.size()) {
        if (sm1[i] < sm2[j]) {
            res.push_back(sm1[i++]);
        } else if (sm1[i] > sm2[j]) {
            res.push_back(sm2[j++]);
        } else {
            res.push_back(sm1[i]);
            i++;
            j++;
        }
    }

    while (i < sm1.size()) {
        res.push_back(sm1[i++]);
    }

    while (j < sm2.size()) {
        res.push_back(sm2[j++]);
    }

    printResult(res);
}

void sym(const vector<int>& mas1, const vector<int>& mas2) {
    vector<int> res;
    vector<int> sm1 = mas1;
    vector<int> sm2 = mas2;
    
    sort(sm1.begin(), sm1.end());
    sort(sm2.begin(), sm2.end());

    int i = 0, j = 0;
    while (i < sm1.size() && j < sm2.size()) {
        if (sm1[i] < sm2[j]) {
            res.push_back(sm1[i++]);
        } else if (sm1[i] > sm2[j]) {
            res.push_back(sm2[j++]);
        } else {
            i++;
            j++;
        }
    }

    while (i < sm1.size()) {
        res.push_back(sm1[i++]);
    }

    while (j < sm2.size()) {
        res.push_back(sm2[j++]);
    }

    printResult(res);
}

int main() {
    int N, M;
    
    cin >> N;
    if (N < 1 || N > 100) {
        return 1;
    }

    vector<int> mas1(N);
    for (int i = 0; i < N; i++) {
        cin >> mas1[i];
        if (mas1[i] < 1 || mas1[i] > 100) {
            return 1;
        }
    }

    cin >> M;
    if (M < 1 || M > 100) {
        return 1;
    }

    vector<int> mas2(M);
    for (int i = 0; i < M; i++) {
        cin >> mas2[i];
        if (mas2[i] < 1 || mas2[i] > 100) {
            return 1;
        }
    }

    vidn(mas1, mas2); 
    vidn(mas2, mas1);
    per(mas1, mas2);  
    obj(mas1, mas2); 
    sym(mas1, mas2);  

    return 0;
}

