#include <iostream>
#include <vector>
using namespace std;

namespace discretFn {
    void discretCalc(int& nORm, int& nANDm) {
        int n, m;
        cin >> n;
        nORm += n;
        vector<int> arrN(n);
        while (n--) {
            cin >> arrN[n];
        }

        cin >> m;
        nORm += m;
        while (m--) {
            int el1;
            cin >> el1;
            for (int el2 : arrN) {
                if (el1 == el2) {
                    nORm--;
                    nANDm++;
                }
            }
        }
    }
}

int main() {
    int nORm = 0;
    int nANDm = 0;

    discretFn::discretCalc(nORm, nANDm);

    cout << nANDm << endl << nORm;

    return 0;
}