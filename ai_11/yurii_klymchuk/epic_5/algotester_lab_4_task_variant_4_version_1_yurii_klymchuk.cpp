#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

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

    //реалізуємо n - m різницю
    vector<int> difference;
    set_difference(n.begin(), n.end(), m.begin(), m.end(), back_inserter(difference));
    cout << difference.size() << endl;
    for (size_t i = 0; i < difference.size(); i++) {
        if (i > 0) cout << " ";
        cout << difference[i];
    }
    cout << endl;

    //реалізуємо m - n різницю
    vector<int> reverse_difference;
    set_difference(m.begin(), m.end(), n.begin(), n.end(), back_inserter(reverse_difference));
    cout << reverse_difference.size() << endl;
    for (size_t i = 0; i < reverse_difference.size(); i++) {
        if (i > 0) cout << " ";
        cout << reverse_difference[i];
    }
    cout << endl;

    //реалізуємо перетин
    vector<int> intersection;
    set_intersection(n.begin(), n.end(), m.begin(), m.end(), back_inserter(intersection));
    cout << intersection.size() << endl;
    for (size_t i = 0; i < intersection.size(); i++) {
        if (i > 0) cout << " ";
        cout << intersection[i];
    }
    cout << endl;

    //реалізуємо об'єднання
    vector<int> union_set;
    set_union(n.begin(), n.end(), m.begin(), m.end(), back_inserter(union_set));
    cout << union_set.size() << endl;
    for (size_t i = 0; i < union_set.size(); i++) {
        if (i > 0) cout << " ";
        cout << union_set[i];
    }
    cout << endl;

    //реалізуємо симетртчну різницю
    vector<int> symmetric_difference;
    set_symmetric_difference(n.begin(), n.end(), m.begin(), m.end(), back_inserter(symmetric_difference));
    cout << symmetric_difference.size() << endl;
    for (size_t i = 0; i < symmetric_difference.size(); i++) {
        if (i > 0) cout << " ";
        cout << symmetric_difference[i];
    }
    cout << endl;

    return 0;
}
