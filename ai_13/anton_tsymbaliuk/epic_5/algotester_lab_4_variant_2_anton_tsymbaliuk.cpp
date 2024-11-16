#include <iostream>
#include <vector>

void const showArr(const std::vector<int>& arr){
    std::cout << arr.size() << std::endl;
    for(const int& num : arr) std::cout << num << " ";
    std::cout << std::endl;
}

int main(){
    int size;
    std::cin >> size;
    std::vector<int> arr;
    arr.reserve(10 * 10 * 10);
    int p1 = 0, p2 = 0;
    int temp;
    for(int i = 0; i < size; i++){
        std::cin >> temp;
        bool isCopy = false;
        if(temp % 3 == 0){
            if(p1 == 0 || arr[p1 - 1] < temp) arr.insert(arr.begin() + p1, temp);
            else{
                int l = 0;
                int r = p1 - 1;
                int n = r / 2;
                while(l < r){
                    int& val = arr[n];
                    if(val < temp) l = n + 1;
                    else if(val > temp) r = n;
                    else {
                        isCopy = true;
                        break;
                    }
                    n = (r + l) / 2;
                }
                if(l >= r) {
                    if(arr[l] != temp)arr.insert(arr.begin() + l, temp);
                    else isCopy = true;
                }
            }
            if(!isCopy){
                p1++;
                p2++;
            }
            
        }
        else if(temp % 3 == 1){
     
            if(p1 == p2 || p2 == 0 || arr[p2 - 1] > temp) arr.insert(arr.begin() + p2, temp);
            else{
                int l = p1;
                int r = p2 - 1;
                int n = (r + l) / 2;
                while(l < r){
                    int& val = arr[n];
                    if(val > temp) l = n + 1;
                    else if(val < temp) r = n;
                    else {
                        isCopy = true;
                        break;
                    }
                    n = (r + l) / 2;
                }
                if(l >= r) {
                    if(arr[l] != temp)arr.insert(arr.begin() + l, temp);
                    else isCopy = true;
                }
            }
            if(!isCopy)p2++;
        }
        else{
            const int SIZE = arr.size();
            if(p2 == SIZE || SIZE == 0 || arr[SIZE - 1] < temp) arr.push_back(temp);
            else{
                int l = p2;
                int r = SIZE - 1;
                int n = (r + l) / 2;
                while(l < r){
                    int& val = arr[n];
                    if(val < temp) l = n + 1;
                    else if(val > temp) r = n;
                    else {
                        isCopy = true;
                        break;
                    }
                    n = (r + l) / 2;
                }
                if(l >= r) {
                    if(arr[l] != temp)arr.insert(arr.begin() + l, temp);
                    else isCopy = true;
                }
            }
        }
    }
    showArr(arr);
    
}