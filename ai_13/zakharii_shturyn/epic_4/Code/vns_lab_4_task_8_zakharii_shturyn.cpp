#include <iostream>
#include <vector>
using namespace std;

void print(vector<short>& arr) {
    for(short num : arr) {
        cout << num << " ";
    }
}

int main() {

    int size;
    cout << "Enter size of array: ";
    cin >> size;
    vector<short> arr(size);
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    short del;
    cout << "Input element to destroy: ";
    cin >> del;
    vector<short> index(0);
    for(short i = 0; i < arr.size(); i++) {
        if(arr[i] == del) {
            index.push_back(i);
        }
    }
    for(short idx : index){
        arr.erase(arr.begin() + idx);
    }
    cout << "Deleting..." << endl;
    print(arr);

    for(short i = 0; i < arr.size(); i++) {
        if(arr[i] % 2 == 0) {
            arr.insert(arr.begin() + i, 0);
            i++;
        }
    }
    cout << endl << "Adding 0 before eval" << endl;
    print(arr);

    return 0;
}