#include <iostream>
#include <vector>

int main(){
int N, M, counter1 = 0, counter2 = 0;

std::vector<int> array1;
std::vector<int> array2;
std::vector<int> riz;

std::cin >> N;
array1.resize(N);
for(int i = 0; i < array1.size(); ++i)
    std::cin >> array1[i];

std::cin >> M;
array2.resize(M);
for(int i = 0; i < array2.size(); ++i)
    std::cin >> array2[i];


for(int i = 0; i < array1.size(); ++i){
    for(int j = 0; j < array2.size(); ++j){
        if (array1[i] == array2[j])
            ++counter1;
            
    }

}

std::cout << counter1 << std::endl;
std::cout << array1.size() + array2.size() - counter1;

        return 0;
    }