#include <iostream>
#include <vector>
#include <algorithm>


void print(const std::vector<int>& set, int len)
{
    std::cout << len << std::endl;
    for(int i = 0; i < len; i++)
        std::cout << set[i] << " ";
    std::cout << std::endl;
}


int main()
{
    int N;
    std::cin >> N;
    std::vector<int> a(N);

    for(int i = 0; i < N; i++)
        std::cin >> a[i];

    int M;
    std::cin >> M;
    std::vector<int> b(M);

    for(int i = 0; i < M; i++)
        std::cin >> b[i];


    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

//1. Різницю N-M
    std::vector<int> a1;
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(a1));
    print(a1, a1.size());
    std::cout << std::endl;

//2. Різницю M-N
    std::vector<int> b2;
    std::set_difference(b.begin(), b.end(), a.begin(), a.end(), std::back_inserter(b2));
    print(b2, b2.size());
    std::cout << std::endl;

//3. Їх перетин
    std::vector<int> same;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(same));
    print(same, same.size());
    std::cout << std::endl;

//4. Їх обєднання
    std::vector<int> unite;
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(unite));
    print(unite, unite.size());
    std::cout << std::endl;

//5. Їх симетричну різницю
    std::vector<int> sym_diff;
    std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(sym_diff));
    print(sym_diff, sym_diff.size());
    std::cout << std::endl;

    return 0;
}