#include <iostream>
#include <vector>


bool contain(int val, std::vector<int>& arr){
    for(const int& v : arr) if(v == val) return true;
    return false;
}

int main(){
    int n, m;
    std::cin >> n;
    std::vector<int> arr1(n);
    for(int i = 0; i < n; i++) std::cin >> arr1[i];
    std::cin >> m;
    std::vector<int> arr2(m);
    for(int i = 0; i < m; i++) std::cin >> arr2[i];
    int identicalCounter = 0;
    int uniqueCounter = m;
    for(const int& val : arr1) {
        if(contain(val, arr2)) identicalCounter++; 
        else uniqueCounter++;
    }
    std::cout << identicalCounter <<"\n" << uniqueCounter;
    return 0;
}