#include <iostream>
#include <vector>

using namespace std;

void selectSort(vector<int> &vec, int p1, int p2, bool reverse);

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    int p1 = 0, p2 = vec.size();

    for (int i = 0; i < p2;) {
        if (vec[i] % 3 == 0) {
            int element = vec[i];
            vec.erase(vec.begin() + i);
            vec.insert(vec.begin(), element);
            p1++;
            i++;
        } else if (vec[i] % 3 == 2) {
            int element = vec[i];
            vec.erase(vec.begin() + i);
            vec.insert(vec.end(), element);
            p2--;
        } else i++;
    }

    selectSort(vec, 0, p1, false);
    selectSort(vec, p1, p2, true);
    selectSort(vec, p2, vec.size(), false);

    for (int i = 0; i < N - 1;) {
        if (vec[i] == vec[i + 1]) {
            vec.erase(vec.begin() + i + 1);
            N--;
        } else i++;
    }

    cout << vec.size() << endl;
    for (int i = 0; i < N; i++) cout << vec[i] << " ";

    return 0;
}

void selectSort(vector<int> &vec, int p1, int p2, bool reverse) {
    for (int i = p1; i < p2; i++) {
        for (int j = i + 1; j < p2; j++) {
            if (!reverse) {
                if (vec[i] > vec[j]) {
                    int temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
            } else {
                if (vec[i] < vec[j]) {
                    int temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
            }
        }
    }
}