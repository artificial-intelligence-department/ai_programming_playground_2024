#include <iostream>
#include <vector>
#include <algorithm>

int main(){

int N;
std::cin >> N;

std::vector<int> array;
std::vector<int> O1;
std::vector<int> O2;
std::vector<int> O3;

int temp;
for(int i = 0; i < N; ++i){
    std::cin >> temp;
    if((temp % 3) == 0)
        O1.push_back(temp);
    else if ((temp % 3) == 1)
        O2.push_back(temp);
    else
        O3.push_back(temp);
}

std::sort(O1.begin(), O1.end());
std::sort(O3.begin(), O3.end());
std::sort(O2.begin(), O2.end(), std::greater{});

for(int a = 0; a < O1.size(); ++a)
    array.push_back(O1[a]);
for(int b = 0; b < O2.size(); ++b)
    array.push_back(O2[b]);
for(int c = 0; c < O3.size(); ++c)
    array.push_back(O3[c]);
array.erase(std::unique(array.begin(), array.end()), array.end());

std::cout << array.size() << std::endl;
for(auto el:array)
    std::cout << el << ' ';
    return 0;
}