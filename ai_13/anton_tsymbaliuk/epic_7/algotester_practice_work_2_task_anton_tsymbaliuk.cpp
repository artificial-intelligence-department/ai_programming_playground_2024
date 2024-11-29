#include <iostream>
#include <vector>

int main()
{
    std::vector<int> A;
    A.reserve(100);
    int Q;
    std::cin >> Q;
    int t;
    int x;
    int K;
    while (Q) {
        std::cin >> t;
        switch (t)
        {
        case 1:
            std::cin >> x;
            if (A.size() == 0 || x > A[A.size() - 1]) {
                A.push_back(x);
                break;
            }
            if (x < A[0]) {
                A.insert(A.begin(), x);
                break;
            }
            for (int i = 1; i < A.size(); i++) {
                if (x < A[i]) {
                    A.insert(A.begin() + i, x);
                    break;
                }
            }
            break;
        case 2:
            std::cin >> x;
            for (int i = 0; i < A.size(); i++) {
                if (x == A[i]) {
                    A.erase(A.begin() + i);
                    break;
                }
            }
            break;
        case 3:
            std::cin >> K;
            std::cout << A[K - 1] << std::endl;
            break;
        }
        Q--;
    }
}
