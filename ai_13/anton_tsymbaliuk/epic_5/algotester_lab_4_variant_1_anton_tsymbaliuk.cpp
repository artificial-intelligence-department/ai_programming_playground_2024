#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void const showArr(const std::vector<int>& arr){
    std::cout << arr.size() << std::endl;
    for(const int& val : arr) std::cout << val << " ";
    std::cout << std::endl << std::endl;
}

int main(){
    int N, M;
    std::vector<int> set1, set2;
    std::vector<int> res1, res2, res3, res4, res5;
    std::cin >> N;
    int temp;
    for(int i = 0; i < N; i++){
        std::cin >> temp;
        set1.push_back(temp);
    }
    std::cin >> M;
    for(int i = 0; i < M; i++){
        std::cin >> temp;
        set2.push_back(temp);
    }

    std::sort(set1.begin(), set1.end());
    std::sort(set2.begin(), set2.end());

    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(res1));
    
    std::set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), std::back_inserter(res2));
    
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(res3));
    
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(res4));
    
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(res5));

    showArr(res1);
    showArr(res2);
    showArr(res3);
    showArr(res4);
    showArr(res5);
    return 0;
}