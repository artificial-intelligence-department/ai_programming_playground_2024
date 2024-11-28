#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void quickSort(vector <int> &vec, int first, int last){
    int middle = vec[(first + last) / 2];
    int i = first;
    int j = last;
    do{
        while(vec[i] < middle){
            i++;
        }
        while(vec[j] > middle){
            j--;
        }
        if (i <= j){
            swap(vec[i], vec[j]);
            i++;
            j--;
        }
    }while(i <= j);
    if (j > first){
        quickSort(vec, first, j);
    }
    if (i < last){
        quickSort(vec, i, last);
    }
}

void quickSortDescending(vector<int> &vec, int first, int last) {
    int middle = vec[(first + last) / 2];
    int i = first;
    int j = last;
    do {
        while (vec[i] > middle) {
            i++;
        }
        while (vec[j] < middle) {
            j--;
        }
        if (i <= j) {
            swap(vec[i], vec[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (j > first) {
        quickSortDescending(vec, first, j);
    }
    if (i < last) {
        quickSortDescending(vec, i, last);
    }
}

void myUnique(vector <int> &vec, int &size){
    vector <int> uniqueVec;
    for (int num : vec){
        bool found = false;
        for (int uniqnum : uniqueVec){
            if (num == uniqnum){
                found = true;
                size--;
            }
        }
        if (!found){
            uniqueVec.push_back(num);
        }
    }
    vec = uniqueVec;
}

int main() {
    int n, t;
    cin >> n;
    vector <int> vec, ost0Vec, ost1Vec, ost2Vec;
    for (size_t i = 0; i < n; i++)
    {
        cin >> t;
        vec.push_back(t);
        if (t % 3 == 0){
            ost0Vec.push_back(t);
        }
        else if (t % 3 == 1){
            ost1Vec.push_back(t);
        }
        else{
            ost2Vec.push_back(t);
        }

    }
    quickSort(ost0Vec, 0, ost0Vec.size() - 1);
    quickSortDescending(ost1Vec, 0, ost1Vec.size() - 1);
    quickSort(ost2Vec, 0, ost2Vec.size() - 1);
    vector<int>res;
    res.insert(res.end(), ost0Vec.begin(), ost0Vec.end());
    res.insert(res.end(), ost1Vec.begin(), ost1Vec.end());
    res.insert(res.end(), ost2Vec.begin(), ost2Vec.end());
    int sizeOst = res.size();
    myUnique(res, sizeOst);
    cout << sizeOst << endl;
    for (int i = 0; i < sizeOst; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}