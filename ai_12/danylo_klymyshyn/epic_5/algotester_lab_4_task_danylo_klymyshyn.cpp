#include <iostream>
#include <vector>

void merge(std::vector<int> &v, int left, int mid, int right){

    int n1 = mid-left + 1; 
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; ++i)
        L[i] = v[left+i];
    for(int j = 0; j < n2; ++j)
        R[j] = v[mid+1+j];
    
    int i = 0, j = 0, k = left; 
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            ++i;
        }
        else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }


    while(i < n1){
        v[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2){
        v[k] = R[j];
        ++j;
        ++k;
    }
}



void mergesort(std::vector<int> &v, int left, int right){
    if(left >= right)
        return ;

    int mid = left + (right - left)/2;

    mergesort(v, left, mid);
    mergesort(v, mid+1, right);
    merge(v, left, mid, right);

}



void merge_rev(std::vector<int> &v, int left, int mid, int right){
    int n1 = mid-left + 1; 
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; ++i)
        L[i] = v[left+i];
    for(int j = 0; j < n2; ++j)
        R[j] = v[mid+1+j];
    
    int i = 0, j = 0, k = left; 
    while(i < n1 && j < n2){
        if(L[i] >= R[j]){
            v[k] = L[i];
            ++i;
        }
        else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }


    while(i < n1){
        v[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2){
        v[k] = R[j];
        ++j;
        ++k;
    }

}

void mergesort_rev(std::vector<int> &v, int left, int right){
    if(left >= right)
        return ;

    int mid = left + (right - left)/2;

    mergesort_rev(v, left, mid);
    mergesort_rev(v, mid+1, right);
    merge_rev(v, left, mid, right);

}

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

mergesort(O1, 0, O1.size()-1);
mergesort(O3, 0, O3.size()-1);
mergesort_rev(O2, 0, O2.size()-1);


for(int a = 0; a < O1.size(); ++a)
    array.push_back(O1[a]);
for(int b = 0; b < O2.size(); ++b)
    array.push_back(O2[b]);
for(int c = 0; c < O3.size(); ++c)
    array.push_back(O3[c]);

for(int i = array.size()-1; i > 0; --i){
    if(array[i] == array[i-1]){
        array.erase(array.begin()+ i);
    }   
}

std::cout << array.size() << std::endl;
for(auto el:array)
    std::cout << el << ' ';


    return 0;
}