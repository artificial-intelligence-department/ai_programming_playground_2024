#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>


void printsc(const std::vector<int>& v) {
    std::cout << v.size() << std::endl;
    for (const auto& el : v) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}

int main() {
    size_t N, M;
    std::cin >> N;
    std::vector<int> v1(N);
    for (size_t i = 0; i < N; i++) {
        std::cin >> v1[i];
    }
    
    std::cin >> M;
    std::vector<int> v2(M);
    for (size_t i = 0; i < M; i++) {
        std::cin >> v2[i];
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    // N - M 
    std::vector<int> NdM;
    std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(NdM));
    printsc(NdM);
    std::cout << std::endl;

    // M - N 
    std::vector<int> MnD;
    std::set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), std::back_inserter(MnD));
    printsc(MnD);
    std::cout << std::endl;

    // M with N 
    std::vector<int> MwithN;
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(MwithN));
    printsc(MwithN);
    std::cout << std::endl;
    // M and N
    std::vector<int> MandN;
    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(MandN));
    printsc(MandN);
    std::cout << std::endl;

    // M <-> N 
    std::vector<int> MsN;
    std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(MsN));
    printsc(MsN);


    return 0;
}

