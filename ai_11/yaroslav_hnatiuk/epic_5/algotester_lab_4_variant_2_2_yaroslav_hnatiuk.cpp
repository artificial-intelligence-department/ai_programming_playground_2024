#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vec[i] > vec[j]) {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }

    for (int i = 0; i < N - 1;) {
        if (vec[i] == vec[i + 1]) {
            vec.erase(vec.begin() + i + 1);
            N--;
        } else i++;
    }


    while (K != 0) {
        vec.push_back(vec[0]);
        vec.erase(vec.begin());
        K--;
    }

    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) cout << vec[i] << " ";

    return 0;
}