#include <iostream>
#include <vector>
#include <algorithm>


void print(const std::vector<int>& set, int len);


int main()
{
    int N;
    std::cin >> N;
    std::vector<int> set_1(N);

    for(int i = 0; i < N; i++)
        std::cin >> set_1[i];

    int M;
    std::cin >> M;
    std::vector<int> set_2(M);

    for(int i = 0; i < M; i++)
        std::cin >> set_2[i];


    std::sort(set_1.begin(), set_1.end());
    std::sort(set_2.begin(), set_2.end());

    //N-M
    std::vector<int> NDdif;
    std::set_difference(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(), std::back_inserter(NDdif));
    print(NDdif, NDdif.size());
    std::cout << std::endl;

    //M-N
    std::vector<int> MDdif;
    std::set_difference(set_2.begin(), set_2.end(), set_1.begin(), set_1.end(), std::back_inserter(MDdif));
    print(MDdif, MDdif.size());
    std::cout << std::endl;

    //Intersection
    std::vector<int> NDinters;
    std::set_intersection(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(), std::back_inserter(NDinters));
    print(NDinters, NDinters.size());
    std::cout << std::endl;

    //Union
    std::vector<int> NDunion;
    std::set_union(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(), std::back_inserter(NDunion));
    print(NDunion, NDunion.size());
    std::cout << std::endl;

    //Symetric_difference
    std::vector<int> NDsymdiff;
    std::set_symmetric_difference(set_1.begin(), set_1.end(), set_2.begin(), set_2.end(), std::back_inserter(NDsymdiff));
    print(NDsymdiff, NDsymdiff.size());
    std::cout << std::endl;

    

    return 0;


}

void print(const std::vector<int>& set, int len)
{
    std::cout << len << std::endl;
    for(int i = 0; i < len; i++)
        std::cout << set[i] << " ";
    std::cout << std::endl;
}
