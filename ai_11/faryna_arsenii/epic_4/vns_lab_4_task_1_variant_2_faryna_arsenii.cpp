#include <iostream>

using namespace std;

//prototype of function
void filled_array(int* arr[], int& user_input);
void print_array(const int* arr[], int& user_input);
void delete_first_element(int* arr[], int& user_input);
void add_element(int* arr[], int& user_input);

void filled_array(int arr[], int user_input) {
    for (int i = 0; i < user_input; i++){ 
        arr[i] = rand() % 100;
    }
}

void print_array(const int arr[], int user_input){
    for (int i = 0; i < user_input; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void delete_first_element(int arr[], int user_input){
    for (int i = 0; i < user_input - 1; i++){
        arr[i] = arr[i + 1];
    } 
    arr[user_input - 1] = 0; //for deleted element which will be replaced in the end of massive
    user_input--;
}

void add_element(int arr[], int user_input) {
    const int MAX_SIZE = 100;
    
    for (int i = 0; i < user_input; i++) {
        if (arr[i] % 2 == 0 && user_input < MAX_SIZE) { 
            for (int k = user_input; k > i + 1; k--) { 
                arr[k] = arr[k - 1];
            }
            arr[i + 1] = arr[i] + 2; 
            user_input++; 
            i++; 
        }
    }
}

int main() {

    srand(static_cast<unsigned> (time(nullptr)));

    int user_input;
    const int SIZE = 100;
    int arr[SIZE];
    cout << "Enter the array length: ";
    cin >> user_input;

    if (user_input > SIZE){
        cout << "Error! Maximum allowed input is: " << SIZE << endl;
        return -1;
    }
    
    filled_array(arr, user_input);
    cout << "Array filled with random element: " << endl; 
    print_array(arr, user_input);
    
    delete_first_element(arr, user_input);
    cout << "Array after deleting first element: " << endl;
    print_array(arr, user_input); 
    
    add_element(arr, user_input);
    cout << "Array after adding to pair element in massive " << endl;
    print_array(arr, user_input);

    return 0;
}
