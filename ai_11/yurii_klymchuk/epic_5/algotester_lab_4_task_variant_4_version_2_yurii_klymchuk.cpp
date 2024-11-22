#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//функція для виводу результатів операцій
void PrintResult (const vector<int>& result){
        cout << result.size() << endl;
        for (int x : result) cout << x << " ";
        cout << endl;
}

//функція для об'єднання множин
vector<int> SetUnion(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) result.push_back(a[i++]);
        else if (b[j] < a[i]) result.push_back(b[j++]);
        else {
            result.push_back(a[i]);
            i++; j++;
        }
    }
    while (i < a.size()) result.push_back(a[i++]);
    while (j < b.size()) result.push_back(b[j++]);
    return result;
}

//функція для перетину множин
vector<int> Intersection(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) i++;
        else if (b[j] < a[i]) j++;
        else {
            result.push_back(a[i]);
            i++; j++;
        }
    }
    return result;
}

//функція для знаходження різниці
vector<int> Difference(const vector<int>& a, const vector<int>& b){
    vector<int> result;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) result.push_back(a[i++]);
        else if (b[j] < a[i]) j++;
        else {
            i++;
            j++;
        }
    }
    while (i < a.size()) result.push_back(a[i++]);
    return result;
}

//функція для симетричної різниці (з використанням попередніх функцій)
vector<int> SymmetricDifference(const vector<int>& a, const vector<int>& b) {
    vector<int> result1 = Difference(a, b);
    vector<int> result2 = Difference(b, a);
    return SetUnion(result1, result2);
}

int main() {
    int N, M;

    //считуємо розмір та значенння першої множини
    cin >> N;
    vector<int> n(N);
    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    //считуємо розмір та значенння другої множини
    cin >> M;
    vector<int> m(M);
    for (int i = 0; i < M; i++) {
        cin >> m[i];
    }

    //сортуємо вектори
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());

    //записуємо результати операцій
    vector<int> diff1 = Difference(n, m);
    vector<int> diff2 = Difference(m, n);
    vector<int> intersection = Intersection(n, m);
    vector<int> union_set = SetUnion(n, m);
    vector<int> sym_diff = SymmetricDifference(n, m);

    //виводимо результати
    PrintResult(diff1);
    PrintResult(diff2);
    PrintResult(intersection);
    PrintResult(union_set);
    PrintResult(sym_diff);       

    return 0;
}
